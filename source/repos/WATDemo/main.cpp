/*************************************************************************
【文件名】                 （main.cpp)
【功能模块和目的】         （主函数,开始程序)
【开发者及日期】           （范静涛 2021.7.29)
*************************************************************************/
#include "loginwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QStringList>
/*************************************************************************
【函数名称】       （main)
【函数功能】       （主函数,建立LoginWindow对象,开始程序)
【参数】           （主函数参数int argc, char* argv[])
【返回值】         （整型,表示程序运行结果)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
int main(int argc, char* argv[]) {
    qputenv("QT_MAC_WANTS_LAYER", "1");
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    w.move((QApplication::desktop()->width() - w.width()) / 2,
           (QApplication::desktop()->height() - w.height()) / 2);
    return a.exec();
}
