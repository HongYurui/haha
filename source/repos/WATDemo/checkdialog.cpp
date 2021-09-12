/*************************************************************************
【文件名】                 （checkdialog.cpp)
【功能模块和目的】         （界面类,定义关闭确认窗口类CheckDialog的函数)
【开发者及日期】           （洪宇睿 2021.7.31)
*************************************************************************/
#include "checkdialog.h"
#include "ui_checkdialog.h"
/*************************************************************************
【函数名称】       （CheckDialog)
【函数功能】       （构造函数,创建ui界面)
【参数】           （父窗口指针*parent)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
CheckDialog::CheckDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::CheckDialog) {
    ui->setupUi(this);
}
/*************************************************************************
【函数名称】       （~CheckDialog)
【函数功能】       （析构函数,释放ui指向的界面内存)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
CheckDialog::~CheckDialog() {
    delete ui;
}
/*************************************************************************
【函数名称】       （on_CheckDialogButtonBox_accepted)
【函数功能】       （槽函数,控制登录窗口的显示,普通用户窗口或管理员窗口的隐藏)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
【修改记录】       （洪宇睿 2021.8.5 修改了指针的传递方式)
*************************************************************************/
void CheckDialog::on_CheckDialogButtonBox_accepted() {
    LoginWindow* pLoginWindow = LoginWindow::SetpLoginWindow();
    MainWindow* pMainWindow = pLoginWindow->FetchpMainWindow();
    AdMainWindow* pAdMainWindow = pLoginWindow->FetchpAdMainWindow();
    pLoginWindow->show();
    if (pMainWindow != nullptr) {
        pMainWindow->hide();
    }
    if (pAdMainWindow != nullptr) {
        pAdMainWindow->hide();
    }
}
