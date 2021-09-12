/*************************************************************************
【文件名】                 （loginwindow.h)
【功能模块和目的】         （界面类,声明登录窗口类)
【开发者及日期】           （范静涛 2021.7.29)
*************************************************************************/
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "logincontroler.h"
#include "admainwindow.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE
/*************************************************************************
【类名】             （LoginWindow)
【功能】             （界面类,实现用户登录窗口)
【接口说明】         （构造、析构函数,返回自身指针的SetpLoginWindow,调用外部函数
                      返回用户类和管理员类指针的SetpMainWindow和SetpAdMainWindow)
【开发者及日期】     （2021.7.29 范静涛)
【修改信息】         （洪宇睿 2021.7.31 实现功能,但结构混乱)
                    （洪宇睿 2021.8.4 调整了指针)
*************************************************************************/
class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*构造函数*/
    LoginWindow(QWidget* parent = nullptr);

    /*析构函数*/
    ~LoginWindow();

    /*静态函数,返回自身指针*/
    static LoginWindow* SetpLoginWindow();

    /*传递指向的用户窗口指针*/
    MainWindow* FetchpMainWindow() const;

    /*传递指向的管理员窗口指针*/
    AdMainWindow* FetchpAdMainWindow() const;

private slots:
    /*槽函数,负责按下登录按钮后的窗口行为*/
    void on_btnLogin_clicked();

private:
    /*窗口界面指针*/
    Ui::LoginWindow* ui;

    /*自身指针*/
    static LoginWindow* pLoginWindow;

    /*指向的用户窗口指针*/
    static MainWindow* pMainWindow;

    /*指向的管理员窗口指针*/
    static AdMainWindow* pAdMainWindow;

    /*建立的控制器实例*/
    LoginControler Controler;
};

#endif // LOGINWINDOW_H
