/*************************************************************************
【文件名】                 （adduserdialog.h)
【功能模块和目的】         （定义添加用户窗口类函数)
【开发者及日期】           （洪宇睿 2021.7.31)
*************************************************************************/
#include "adduserdialog.h"
#include "ui_adduserdialog.h"
#include <QMessageBox>
#include <string>

using namespace std;
/*************************************************************************
【函数名称】       （AddUserDialog)
【函数功能】       （构造函数,构造窗口的界面)
【参数】           （父窗口指针*parent)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
AddUserDialog::AddUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUserDialog) {
    ui->setupUi(this);
}
/*************************************************************************
【函数名称】       （~AddUserDialog)
【函数功能】       （析构函数,释放ui指向的界面内存)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
AddUserDialog::~AddUserDialog() {
    delete ui;
}
/*************************************************************************
【函数名称】       （on_buttonBox_accepted)
【函数功能】       （槽函数,按钮被点击时调用AddUser,根据返回值作出不同反应)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
void AddUserDialog::on_buttonBox_accepted() {
    AddUserResult Res = addUserControler.AddUser(
                ui->lineEdit->text().toStdString(),
                ui->lineEdit_2->text().toStdString());
    if (Res == AddUserResult::EMPTY_NAME) {
        QMessageBox::information(NULL, "添加失败", "用户名不能为空！", QMessageBox::Ok);
    }
    else if (Res == AddUserResult::EMPTY_PASSWORD) {
        QMessageBox::information(NULL, "添加失败", "密码不能为空！" , QMessageBox::Ok);
    }
    else if (Res == AddUserResult::ADDUSER_SUCCEEDED) {
        QMessageBox::information(NULL, "添加成功", "已新建用户" + ui->lineEdit->text()
                                 + "！" , QMessageBox::Ok);
    }
    else if (Res == AddUserResult::ADMIN_EXISTED) {
        QMessageBox::information(NULL, "添加失败", "无法新建与管理员重名的用户！",
                                 QMessageBox::Ok);
    }
    else {
        QMessageBox::information(NULL, "添加失败", "用户已存在！", QMessageBox::Ok);
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}
