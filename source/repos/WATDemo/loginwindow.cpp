/*************************************************************************
【文件名】                 （loginwindow.cpp)
【功能模块和目的】         （界面类,实现用户登录窗口)
【开发者及日期】           （范静涛 2021.7.29)
*************************************************************************/
#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
/*指针成员的初始化*/
LoginWindow* LoginWindow::pLoginWindow = nullptr;
MainWindow* LoginWindow::pMainWindow = nullptr;
AdMainWindow* LoginWindow::pAdMainWindow = nullptr;
/*************************************************************************
【函数名称】       （LoginWindow)
【函数功能】       （构造函数)
【参数】           （父窗口指针*parent)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
【修改信息】        （洪宇睿 2021.7.31 增加了指向窗口指针的声明)
*************************************************************************/
LoginWindow::LoginWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow) {
    ui->setupUi(this);
    pLoginWindow = this;
}
/*************************************************************************
【函数名称】       （~LoginWindow)
【函数功能】       （析构函数,释放ui指向的界面内存)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
LoginWindow::~LoginWindow() {
    delete ui;
}
/*************************************************************************
【函数名称】       （SetpLoginWindow)
【函数功能】       （返回当前LoginWindow对象的指针)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.5)
*************************************************************************/
LoginWindow* LoginWindow::SetpLoginWindow() {
    return pLoginWindow;
}
/*************************************************************************
【函数名称】       （FetchpMainWindow)
【函数功能】       （返回当前LoginWindow成员指针pMainWindow)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.5)
*************************************************************************/
MainWindow* LoginWindow::FetchpMainWindow() const {
    return LoginWindow::pMainWindow;
}
/*************************************************************************
【函数名称】       （FetchpAdMainWindow)
【函数功能】       （返回当前LoginWindow成员指针pAdMainWindow)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.5)
*************************************************************************/
AdMainWindow* LoginWindow::FetchpAdMainWindow() const {
    return LoginWindow::pAdMainWindow;
}
/*************************************************************************
【函数名称】       （on_btnLogin_clicked)
【函数功能】       （槽函数,调用Login函数进行登录操作,并在界面中处理异常)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
void LoginWindow::on_btnLogin_clicked() {
    LoginResult Res = Controler.Login(
                ui->edtUserName->text().toStdString(),
                ui->edtPassword->text().toStdString());

    ui->edtPassword->clear();
    if (Res == LoginResult::EMPTY_NAME) {
        QMessageBox::information(NULL, "登录失败", "用户名不能为空！", QMessageBox::Ok);
    }
    else if (Res == LoginResult::EMPTY_PASSWORD) {
        QMessageBox::information(NULL, "登录失败", "密码不能为空！", QMessageBox::Ok);
    }
    else if (Res == LoginResult::WRONG_PASSWORD) {
        QMessageBox::information(NULL, "登录失败", "密码错误！", QMessageBox::Ok);
    }
    else {
        if (Res == LoginResult::NO_USER) {
            QMessageBox::information(NULL, "登录失败", "用户名不存在！", QMessageBox::Ok);
        }
        else if (Res == LoginResult::ADMIN_LOGINED) {
            QMessageBox::information(NULL, "登录成功", "管理员已登录！", QMessageBox::Ok);
            pAdMainWindow = AdMainWindow::SetpAdMainWindow();
            pAdMainWindow->show();
            this->hide();
        }
        else {
            QMessageBox::information(NULL, "登录成功", "用户 "
                + ui->edtUserName->text() + " 已登录！", QMessageBox::Ok);
            pMainWindow = MainWindow::SetpMainWindow();
            pMainWindow->show();
            this->hide();
        }
        ui->edtUserName->clear();
    }
}
