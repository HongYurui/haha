/*************************************************************************
【文件名】                 （admainwindow.h)
【功能模块和目的】         （界面类,继承用户窗口类并添加管理员功能按钮)
【开发者及日期】           （2021.7.31)
【修改记录】              （洪宇睿 2021.8.5 添加初始化函数SetpAdMainWindow的声明)
*************************************************************************/
#ifndef ADMAINWINDOW_H
#define ADMAINWINDOW_H

#include "mainwindow.h"
#include "adduserdialog.h"

namespace Ui {
class AdMainWindow;
}
/*************************************************************************
【类名】             （AdMainWindow)
【功能】             （界面类,继承MainWindow类的功能,并添加管理员控制窗口)
【接口说明】         （显式构造函数AdMainWindow,析构函数~AdMainWindow,初始化函数SetpAdMainWindow)
【开发者及日期】     （洪宇睿 2021.7.31)
【修改记录】         （洪宇睿 2021.8.5 添加初始化函数SetpAdMainWindow的声明)
*************************************************************************/
class AdMainWindow : public MainWindow
{
    Q_OBJECT

public:
    /*显式构造函数*/
    explicit AdMainWindow(QWidget* parent = nullptr);

    /*析构函数*/
    ~AdMainWindow();

    /*返回管理员窗口指针的传递函数*/
    static AdMainWindow* SetpAdMainWindow();

private:
    /*指向管理员窗口的指针*/
    static AdMainWindow* pAdMainWindow;

     /*指向管理员功能按钮的指针*/
    QPushButton* pAdminButton;

    /*指向管理员对话框按钮的指针*/
    AddUserDialog* pAddUserDialog;
};


#endif // ADMAINWINDOW_H
