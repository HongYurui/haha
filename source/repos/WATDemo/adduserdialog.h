/*************************************************************************
【文件名】                 （adduserdialog.h)
【功能模块和目的】         （声明添加用户窗口类)
【开发者及日期】           （洪宇睿 2021.7.31)
*************************************************************************/
#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include "addusercontroler.h"
#include <QDialog>

namespace Ui {
class AddUserDialog;
}
/*************************************************************************
【类名】             （AddUserDialog)
【功能】             （界面类,调用AddUser联系控制器类,通过ui实现可视化)
【接口说明】         （显式构造函数AddUserDialog,析构函数~AddUserDialog)
【开发者及日期】     （洪宇睿)
*************************************************************************/
class AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    /*构造函数*/
    explicit AddUserDialog(QWidget* parent = nullptr);

    /*析构函数*/
    ~AddUserDialog();

private:
    /*界面指针*/
    Ui::AddUserDialog *ui;

    /*添加用户控制器对象*/
    AddUserControler addUserControler;

private slots:
    void on_buttonBox_accepted();
};

#endif // ADDUSERDIALOG_H
