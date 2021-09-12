/*************************************************************************
【文件名】                 （date.h)
【功能模块和目的】         （声明可复用的Date类)
【开发者及日期】           （洪宇睿 2021.8.1)
*************************************************************************/
#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

/*************************************************************************
【类名】             （Date)
【功能】             （实现可复用的时间类,包括时分秒,并有检查器)
【接口说明】         （常引用变量uYear,uMonth,uDay,weekDay,构造函数,拷贝构造函数,
                      重载赋值运算符,重载比较运算符,Set赋值函数,InDays转天数函数,
                      IsLeapYear判断闰年函数，IsValid判断有效格式函数,重载左右++,
                     --运算符,重载重定向输入输出运算符,重定向减法运算符)
【开发者及日期】     （洪宇睿 2021.8.1)
*************************************************************************/
class Date
{
public:
    /*常引用*/
    const unsigned int& uYear;
    const unsigned int& uMonth;
    const unsigned int& uDay;
    const unsigned int& uWeekDay;

    /*默认构造函数*/
    Date();
    /*构造函数*/
    Date(unsigned int uYear,
         unsigned int uMonth,
         unsigned int uDay);

    /*析构函数*/
    ~Date();

    /*拷贝构造函数*/
    Date(const Date& date);

    /*重载赋值运算符*/
    Date operator=(const Date& date);

    /*调用IsValid和InSelectedDomain判断后给时间对象赋值*/
    void Set(unsigned int uYear, unsigned int uMonth,
                                    unsigned int uDay);
    void SetYear(unsigned int uYear);
    void SetMonth(unsigned int uMonth);
    void SetDay(unsigned int uDay);

    /*把日期转化为自公元1年1月1日来的天数*/
    unsigned int InDays() const;

    /*判断日期合理性*/
    static bool IsLeapYear(unsigned int uYear);
    static bool IsValid(unsigned int uYear, unsigned int uMonth,
                                               unsigned int uDay);
    /*重载比较运算符*/
    bool operator==(const Date& date) const;
    bool operator!=(const Date& date) const;
    bool operator>(const Date& date) const;
    bool operator>=(const Date& date) const;
    bool operator<=(const Date& date) const;
    bool operator<(const Date& date) const;

    /*重载左++运算符*/
    Date& operator++();

    /*重载右++运算符*/
    Date operator++(int);

    /*重载左--运算符*/
    Date& operator--();

    /*重载右--运算符*/
    Date operator--(int);

    /*重载减法运算符，返回按日计算的两日期之差*/
    int operator-(const Date& date) const;

    /*友元重载重定向输出流运算符*/
    friend ostream& operator<<(ostream& Stream, const Date& date);

    /*友元重载重定向输入流运算符*/
    friend istream& operator>>(istream& Stream, Date& date);

private:
    /*私有成员变量年月日*/
    unsigned int m_uYear;
    unsigned int m_uMonth;
    unsigned int m_uDay;

    /*私有成员变量,一星期中的星期几*/
    unsigned int m_WeekDay;

    /*静态成员变量,存储在闰年/非闰年每月天数,用于计算*/
    static const unsigned int DaysInMonth[2][13];

    /*静态成员变量,存储平年的天数*/
    static const unsigned int GrigoreyYear;
};

#endif // DATE_H
