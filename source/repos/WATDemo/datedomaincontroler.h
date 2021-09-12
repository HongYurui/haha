/*************************************************************************
【文件名】                 （datedomaincontroler.h)
【功能模块和目的】         （控制器类,声明用户窗口控制器)
【开发者及日期】           （2021.8.1)
【修改记录】               （2021.8.2 添加SelectMessage函数)
*************************************************************************/
#ifndef DATEDOMAINCONTROLER_H
#define DATEDOMAINCONTROLER_H

#include "date.h"
#include "mytime.h"
#include <string>

using namespace std;
/*************************************************************************
【类名】             （SetDomainResult)
【功能】             （枚举类,用于存储日期范围设定的异常信息)
【接口说明】         （枚举常量INVALID_DATE(无效日期),DATE_OVERFLOW(日期越界),
                      TRAVERSED_DATE(日期颠倒),SETDOMAIN_SUCCEEDED(设置成功))
【开发者及日期】     （洪宇睿 2021.8.1)
*************************************************************************/
enum class SetDomainResult
{
    INVALID_DATE,
    DATE_OVERFLOW,
    TRAVERSED_DATE,
    SETDOMAIN_SUCCEEDED
};
/*************************************************************************
【类名】             （SetTimeResult)
【功能】             （枚举类,用于存储消息时间设定的异常信息)
【接口说明】         （枚举常量INVALID_TIME(无效时间),TIME_OVERFLOW(时间越界),
                      SETDOMAIN_SUCCEEDED(设置成功))
【开发者及日期】     （洪宇睿 2021.8.1)
*************************************************************************/
enum class SetTimeResult
{
    INVALID_DATE,
    TIME_OVERFLOW,
    SETTIME_SUCCEEDED
};
/*************************************************************************
【类名】             （DateDomainControler)
【功能】             （控制器类,实现日期时间和消息的控制)
【接口说明】         （构造函数,析构函数,搜索范围设置函数SetDomain,
                     消息时间设置函数SetTime,消息记录函数RecordMessage,
                    消息传递函数FetchMessages)
【开发者及日期】     （洪宇睿 2021.8.1)
*************************************************************************/
class DateDomainControler
{
public:
    /*构造函数*/
    DateDomainControler();

    /*析构函数*/
    ~DateDomainControler();

    /*设定范围函数,返回设定结果信息*/
    SetDomainResult SetDomain(Date& date1, Date& date2) const;

    /*设定消息时间函数,返回设定结果信息*/
    SetTimeResult SetTime(Date& date, Time& time) const;

    /*记录新消息函数，调用InsertMessage在序列中合理的位置新建消息*/
    void RecordMessage(Date& date, Time& time,
                       string& type, string& contents) const;

    /*传递消息函数,取得应传给窗口输出的消息*/
    string FetchMessages(Date& date1, Date& date2, string& type) const;
};

#endif // DATEDOMAINCONTROLER_H
