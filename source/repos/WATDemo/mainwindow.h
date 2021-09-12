/*************************************************************************
【文件名】                 (mainwindow.h)
【功能模块和目的】         (界面类,声明MainWindow类)
【开发者及日期】           (洪宇睿 2021.7.31)
【修改记录】              (洪宇睿 2021.8.1 增加on_pushButtonSend_clicked的声明)
                           (洪宇睿 2021.8.5 修改成员指针变量)
*************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "datedomaincontroler.h"
#include "message.h"
#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}
/*************************************************************************
【类名】            (MainWindow)
【功能】            (界面类,实现用户窗口)
【接口说明】         (显式构造函数,析构函数,返回自身指针的SetpMainWindow函数)
【开发者及日期】     (洪宇睿 2021.7.31)
【修改记录】         (洪宇睿 2021.8.1 增加on_pushButtonSend_clicked的声明)
                    (洪宇睿 2021.8.5 修改成员指针变量)
*************************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*构造函数*/
    explicit MainWindow(QWidget* parent = nullptr);

    /*析构函数*/
    ~MainWindow();

    /*传递自身指针,如为空则构造*/
    static MainWindow* SetpMainWindow();

protected:
    /*界面指针*/
    Ui::MainWindow* ui;

private:

    /*静态变量,存储自身指针*/
    static MainWindow* pMainWindow;

    /*指向对应的退出确认提示框的指针*/
    QDialog* pCheckDialog;

    /*对应的控制器实例*/
    DateDomainControler dateDomainControler;

private slots:
    /*按下退出登录按钮时,负责窗口行为,显示确认退出窗口*/
    void on_pushButtonLogOut_clicked();

    /*按下搜索按钮时,尝试搜索,处理异常信息,正常则显示搜索结果*/
    void on_pushButtonSearch_clicked();

    /*按下“全部”按钮时,切换到“全部消息”模式,显示全部消息*/
    void on_pushButtonChat_clicked();

    /*按下“一言”按钮时,切换到“一言”模式,显示“一言”消息*/
    void on_pushButtonAction_clicked();

    /*按下“一行”按钮时,切换到“一行”模式,显示“一行”消息*/
    void on_pushButtonThought_clicked();

    /*按下“一念”按钮时,切换到“一念”模式,显示“一念”消息*/
    void on_pushButtonAll_clicked();

    /*按下“发送”按钮时,尝试发送编辑框消息,处理异常信息*/
    void on_pushButtonSend_clicked();
};

#endif // MAINWINDOW_H
