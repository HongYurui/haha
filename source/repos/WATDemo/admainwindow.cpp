/*************************************************************************
【文件名】                 （admainwindow.cpp)
【功能模块和目的】         （定义admainwindow管理员类,添加管理员功能按钮)
【开发者及日期】           （洪宇睿 2021.7.31)
【修改记录】               （洪宇睿 2021.8.5 添加SetpAdmain函数)
*************************************************************************/
#include "admainwindow.h"
#include "administrator.h"
/*************************************************************************
【函数名称】       （AdMainWindow)
【函数功能】       （构造函数,继承MainWindow类构造函数,并添加管理员功能按钮)
【参数】           （父窗口指针*parent)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
AdMainWindow* AdMainWindow::pAdMainWindow = nullptr;

AdMainWindow::AdMainWindow(QWidget *parent)
    : MainWindow(parent) {
    AdMainWindow::pAdMainWindow = this;
    pAdminButton = new QPushButton(this);
    pAdminButton->setText("管理员功能");
    pAdminButton->resize(93, 28);
    pAdminButton->move(5, 30);
    pAddUserDialog = new AddUserDialog(this);

    connect(pAdminButton, SIGNAL(clicked()), pAddUserDialog, SLOT(show()));
}
/*************************************************************************
【函数名称】       （~AdMainWindow)
【函数功能】       （析构函数,继承MainWindow类析构函数)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
AdMainWindow::~AdMainWindow() {
    /*继承MainWindow类的析构函数*/
}
/*************************************************************************
【函数名称】       （SetpAdMainWindow)
【函数功能】       （当管理员登录而没有管理员窗口时调用构造函数,并返回当前AdMainWindow指针)
【参数】           （空)
【返回值】         （无)
【开发者及日期】   （洪宇睿 2021.8.5)
*************************************************************************/
AdMainWindow* AdMainWindow::SetpAdMainWindow() {
    if (pAdMainWindow == nullptr) {
        pAdMainWindow = new AdMainWindow;
    }
    return pAdMainWindow;
}
