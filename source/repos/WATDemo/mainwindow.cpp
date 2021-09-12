/*************************************************************************
【文件名】                 （mainwindow.cpp)
【功能模块和目的】         （界面类,实现程序的主界面)
【开发者及日期】           （洪宇睿 2021.7.31)
【修改记录】               （洪宇睿 2021.8.1 添加了发送按钮槽函数
                           洪宇睿 2021.8.2 扩充发送按钮槽函数,加入对信息的处理)
*************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "checkdialog.h"
#include <vector>
#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QString>
#include <memory>
#include <string>

using namespace std;
/*静态指针成员的初始化*/
MainWindow* MainWindow::pMainWindow = nullptr;
/*************************************************************************
【函数名称】       （MainWindow)
【函数功能】       （构造函数,初始化界面和成员指针,在界面文本框中显示当前消息)
【参数】           （父窗口指针*parent)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    pMainWindow = this;
    pCheckDialog = new CheckDialog;
    ui->DisplayBox
      ->setPlainText(QString::fromStdString(Message::LinkAll("全部")));
}
/*************************************************************************
【函数名称】       （~MainWindow)
【函数功能】       （析构函数,释放ui指向的界面内存)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
MainWindow::~MainWindow() {
    delete ui;
}
/*************************************************************************
【函数名称】       （SetpMainWindow)
【函数功能】       （若没有创建过MainWindow则创建,返回MainWindow指针)
【参数】           （空)
【返回值】         （指向MainWindow的指针)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
MainWindow* MainWindow::SetpMainWindow() {
    if (pMainWindow == nullptr) {
        pMainWindow = new MainWindow;
    }
    return pMainWindow;
}
/*************************************************************************
【函数名称】       （on_pushButtonLogOut_clicked)
【函数功能】       （槽函数,当点击退出登录时展示LoginWindow供重新登录)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
void MainWindow::on_pushButtonLogOut_clicked() {
    pCheckDialog->show();
}
/*************************************************************************
【函数名称】       （on_pushButtonSearch_clicked)
【函数功能】       （槽函数,当点击搜索按钮时,调用SetDomain设置日期范围,进行异常
                    处理,若一切顺利则调用FetchMessages得到文本而输出到窗口)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
【修改记录】        （洪宇睿 2021.8.1 添加异常处理模块)
                    （洪宇睿 2021.8.2 添加文本输出模块)
                    （洪宇睿 2021.8.5 修改指针)
*************************************************************************/
void MainWindow::on_pushButtonSearch_clicked() {
    Date date1((unsigned int)(ui->spinBoxFirstYear->value()),
               (unsigned int)(ui->spinBoxFirstMonth->value()),
               (unsigned int)(ui->spinBoxFirstDay->value()));

    Date date2((unsigned int)(ui->spinBoxLastYear->value()),
               (unsigned int)(ui->spinBoxLastMonth->value()),
               (unsigned int)(ui->spinBoxLastDay->value()));

    SetDomainResult res = dateDomainControler.SetDomain(date1, date2);

    if (res == SetDomainResult::INVALID_DATE) {
        QMessageBox::information(NULL, "错误",
                                 "请检查日期合理性,重新搜索！", QMessageBox::Ok);
    }
    else if (res == SetDomainResult::DATE_OVERFLOW) {
        QMessageBox::information(NULL, "错误",
                                 "请在合理范围内重新输入日期,重新搜索！", QMessageBox::Ok);
    }
    else if (res == SetDomainResult::TRAVERSED_DATE) {
        QMessageBox::information(NULL, "错误",
                                 "请检查日期起止顺序,重新搜索！", QMessageBox::Ok);
    }
    else {
        string type = "";
        if (!ui->pushButtonAll->isEnabled()) {
            type = "全部";
        }
        else if (!ui->pushButtonChat->isEnabled()) {
            type = "一言";
        }
        else if (!ui->pushButtonAction->isEnabled()) {
            type = "一行";
        }
        else if (!ui->pushButtonThought->isEnabled()) {
            type = "一念";
        }
        else {
            throw invalid_argument("按钮逻辑设置错误！");
        }
        ui->DisplayBox->setPlainText(QString::fromStdString
            (dateDomainControler.FetchMessages(date1, date2, type)));
    }
}
/*************************************************************************
【函数名称】       （on_pushButtonAll_clicked)
【函数功能】       （槽函数,当点击"全部"按钮时冻结之,激活其他按钮,展示全部消息)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
【修改记录】       （洪宇睿 2021.8.2 增加消息展示功能)
*************************************************************************/
void MainWindow::on_pushButtonAll_clicked() {
    ui->pushButtonAll->setEnabled(false);
    ui->pushButtonChat->setEnabled(true);
    ui->pushButtonAction->setEnabled(true);
    ui->pushButtonThought->setEnabled(true);
    ui->DisplayBox
      ->setPlainText(QString::fromStdString(Message::LinkAll("全部")));
}
/*************************************************************************
【函数名称】       （on_pushButtonChat_clicked)
【函数功能】       （槽函数,当点击"一言"按钮时冻结之,激活其他按钮,展示全部"一言")
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
【修改记录】       （洪宇睿 2021.8.2 增加消息展示功能)
*************************************************************************/
void MainWindow::on_pushButtonChat_clicked() {
    ui->pushButtonAll->setEnabled(true);
    ui->pushButtonChat->setEnabled(false);
    ui->pushButtonAction->setEnabled(true);
    ui->pushButtonThought->setEnabled(true);
    ui->DisplayBox
      ->setPlainText(QString::fromStdString(Message::LinkAll("一言")));
}
/*************************************************************************
【函数名称】       （on_pushButtonAction_clicked)
【函数功能】       （槽函数,当点击"一行"按钮时冻结之,激活其他按钮,展示全部"一行")
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
【修改记录】       （洪宇睿 2021.8.2 增加消息展示功能)
*************************************************************************/
void MainWindow::on_pushButtonAction_clicked() {
    ui->pushButtonAll->setEnabled(true);
    ui->pushButtonChat->setEnabled(true);
    ui->pushButtonAction->setEnabled(false);
    ui->pushButtonThought->setEnabled(true);
    ui->DisplayBox
      ->setPlainText(QString::fromStdString(Message::LinkAll("一行")));
}
/*************************************************************************
【函数名称】       （on_pushButtonThought_clicked)
【函数功能】       （槽函数,当点击"一念"按钮时冻结之,激活其他按钮,展示全部"一念")
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
【修改记录】       （洪宇睿 2021.8.2 增加消息展示功能)
*************************************************************************/
void MainWindow::on_pushButtonThought_clicked() {
    ui->pushButtonAll->setEnabled(true);
    ui->pushButtonChat->setEnabled(true);
    ui->pushButtonAction->setEnabled(true);
    ui->pushButtonThought->setEnabled(false);
    ui->DisplayBox
      ->setPlainText(QString::fromStdString(Message::LinkAll("一念")));
}
/*************************************************************************
【函数名称】       （on_pushButtonSend_clicked)
【函数功能】       （槽函数,当点击"发送"按钮时检查编辑框、日期时间、言/行/念
                    按钮状态,进行异常处理,无误则记录消息并显示)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.7.31)
【修改记录】       （洪宇睿 2021.8.2 增加消息展示功能)
*************************************************************************/
void MainWindow::on_pushButtonSend_clicked() {
    if (!ui->radioButtonChat->isChecked()
            && !ui->radioButtonAction->isChecked()
                && !ui->radioButtonThought->isChecked()) {
        QMessageBox::information(NULL, "错误", "请选择一个发表主题！",
                                 QMessageBox::Ok);
        return;
    }
    else if (ui->EditBox->toPlainText().toStdString() == "") {
        QMessageBox::information(NULL, "错误", "内容不能为空！", QMessageBox::Ok);
        return;
    }

    Date date = Date((unsigned int)(ui->spinBoxy->value()),
                     (unsigned int)(ui->spinBoxM->value()),
                     (unsigned int)(ui->spinBoxd->value()));
    Time time = Time((unsigned int)(ui->spinBoxh->value()),
                     (unsigned int)(ui->spinBoxm->value()),
                     (unsigned int)(ui->spinBoxs->value()));

    SetTimeResult res = dateDomainControler.SetTime(date, time);
    if (res == SetTimeResult::INVALID_DATE) {
        QMessageBox::information(NULL, "错误",
             "请检查日期合理性,重新发表！", QMessageBox::Ok);
    }
    else if (res == SetTimeResult::TIME_OVERFLOW) {
        QMessageBox::information(NULL, "错误",
             "请在合理范围内重新输入时间,重新发表！", QMessageBox::Ok);
    }
    else {
        string type = "无题";
        string contents = ui->EditBox->toPlainText().toStdString();
        if (ui->radioButtonChat->isChecked()) {
            type = "一言";
        }
        else if (ui->radioButtonAction->isChecked()) {
            type = "一行";
        }
        else if (ui->radioButtonThought->isChecked()) {
            type = "一念";
        }
        dateDomainControler.RecordMessage(date, time, type, contents);
        ui->EditBox->clear();
        QMessageBox::information(NULL, "成功", "发表成功！", QMessageBox::Ok);
        ui->pushButtonAll->setEnabled(false);
        ui->pushButtonChat->setEnabled(true);
        ui->pushButtonAction->setEnabled(true);
        ui->pushButtonThought->setEnabled(true);
        ui->DisplayBox
          ->setPlainText(QString::fromStdString(Message::LinkAll("全部")));
    }
}
