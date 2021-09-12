/*************************************************************************
【文件名】                 （checkdialog.h)
【功能模块和目的】         （界面类,声明CheDialog关闭确认窗口类)
【开发者及日期】           （洪宇睿 2021.7.31)
*************************************************************************/
#ifndef CHECKDIALOG_H
#define CHECKDIALOG_H

#include <QDialog>
#include "loginwindow.h"

namespace Ui {
class CheckDialog;
}
/*************************************************************************
【类名】             （CheckDialog)
【功能】             （界面类,实现关闭确认窗口,使关闭窗口时进行确认)
【接口说明】         （显式构造函数CheckDialog,析构函数~CheckDialog,)
【开发者及日期】     （洪宇睿 2021.7.31)
*************************************************************************/
class CheckDialog : public QDialog
{
    Q_OBJECT

public:
    /*显式默认构造函数*/
    explicit CheckDialog(QWidget* parent = nullptr);

    /*析构函数*/
    ~CheckDialog();

private slots:
    /*槽函数，负责用户点击按钮后的窗口反应*/
    void on_CheckDialogButtonBox_accepted();

private:
    /*建立UI*/
    Ui::CheckDialog* ui;
};

#endif // CHECKDIALOG_H
