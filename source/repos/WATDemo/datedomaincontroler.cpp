/*************************************************************************
【函数名称】       （DateDomainControler)
【函数功能】       （构造函数)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.1)
*************************************************************************/
#include "datedomaincontroler.h"
#include "message.h"

using namespace std;
/*************************************************************************
【函数名称】       （DateDomainControler)
【函数功能】       （默认构造函数)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.1)
*************************************************************************/
DateDomainControler::DateDomainControler() {

}
/*************************************************************************
【函数名称】       （~DateDomainControler)
【函数功能】       （析构函数)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.1)
*************************************************************************/
DateDomainControler::~DateDomainControler() {

}
/*************************************************************************
【函数名称】       （SetDomain)
【函数功能】       （调用IsValid检验日期合理性,返回异常信息)
【参数】           （两个Date类对象,表示时间起始)
【返回值】         （SetDomainResult中的枚举值)
【开发者及日期】   （洪宇睿 2021.8.1)
*************************************************************************/
SetDomainResult DateDomainControler::SetDomain(Date& date1, Date& date2) const {
    if ((!Date::IsValid(date1.uDay, date1.uMonth, date1.uDay))
        || (!Date::IsValid(date2.uDay, date2.uMonth, date2.uDay))) {
        return SetDomainResult::INVALID_DATE;
    }
    else if (false/*暂不可能出现此情况*/) {
        return SetDomainResult::DATE_OVERFLOW;
    }
    else if (date1 > date2) {
        return SetDomainResult::TRAVERSED_DATE;
    }
    else {
        return SetDomainResult::SETDOMAIN_SUCCEEDED;
    }
}
/*************************************************************************
【函数名称】       （SetTime)
【函数功能】       （调用IsValid检验时间合理性,返回异常信息)
【参数】           （分别指向Date类对象和Time类对象的两个指针)
【返回值】         （SetTimeResult中的枚举值)
【开发者及日期】   （洪宇睿 2021.8.1)
*************************************************************************/
SetTimeResult DateDomainControler::SetTime(Date& date, Time& time) const {
    if (!Date::IsValid(date.uDay, date.uMonth, date.uDay)) {
        return SetTimeResult::INVALID_DATE;
    }
    else if (!Time::IsValid(time.uHour, time.uMinute, time.uSecond)) {
        return SetTimeResult::TIME_OVERFLOW; /*暂不可能出现此情况*/
    }
    else {
        return SetTimeResult::SETTIME_SUCCEEDED;
    }
}
/*************************************************************************
【函数名称】       （FetchMessages)
【函数功能】       （调用Message类中的SelectMessages返回符合标签要求的消息文本)
【参数】           （分别指向两个日期类对象的指针,一个标签字符串)
【返回值】         （字符串,为所有符合条件的文本组合成的最终展示文本)
【开发者及日期】   （洪宇睿 2021.8.5)
*************************************************************************/
string DateDomainControler::FetchMessages(Date& date1,
                                          Date& date2, string& type) const {
    return Message::SelectMessages(date1, date2, type);
}
/*************************************************************************
【函数名称】       （RecordMessage)
【函数功能】       （调用Message类中的InsertMessage,将信息插入到按时间排好的的序列中)
【参数】           （短整型年月日时分秒,言/行/念标签及消息内容字符串)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.5)
*************************************************************************/
void DateDomainControler::
    RecordMessage(Date& date, Time& time,
                  string& type, string& contents) const {
    Message::InsertMessage(date, time, type, contents);
}
