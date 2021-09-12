/*************************************************************************
【文件名】                 （mytime.h)
【功能模块和目的】         （声明可复用的时间类)
【开发者及日期】           （洪宇睿 2021.8.1)
*************************************************************************/
#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

using namespace std;
/*************************************************************************
【类名】             （Time)
【功能】             （实现可复用的时间类,包括时分秒,并有检查器)
【接口说明】         （常引用变量uHour,uMinute,uSecond,构造函数,
                      拷贝构造函数,重载赋值运算符,重载大小比较运算符,Set赋值函数,
                      IsValid判断有效格式函数)
【开发者及日期】     （洪宇睿 2021.8.1)
*************************************************************************/
class Time
{
public:
    /*常引用*/
    const unsigned int &uHour;
    const unsigned int &uMinute;
    const unsigned int &uSecond;

    /*构造函数*/
    Time();

    Time(unsigned int uHour,
         unsigned int uMinute,
         unsigned int uSecond);

    /*析构函数*/
    ~Time();

    /*拷贝构造函数*/
    Time(const Time& time);

    /*重载赋值运算符*/
    Time operator=(const Time& time);

    /*调用IsValid判断后给时间对象赋值*/
    void Set(unsigned int uHour, unsigned int uMinute,
                                    unsigned int uSecond);
    void SetHour(unsigned int uHour);
    void SetMinute(unsigned int uMinute);
    void SetSecond(unsigned int uSecond);
    unsigned int InSeconds() const;

    /*判断时间合理性*/
    static bool IsValid(unsigned int uHour, unsigned int uMinute,
                        unsigned int uSecond);
    /*重载比较运算符*/
    bool operator==(const Time& time) const;
    bool operator!=(const Time& time) const;
    bool operator>(const Time& time) const;
    bool operator>=(const Time& time) const;
    bool operator<=(const Time& time) const;
    bool operator<(const Time& time) const;

    /*重载左++运算符*/
    Time& operator++();

    /*重载右++运算符*/
    Time operator++(int);

    /*重载左--运算符*/
    Time& operator--();

    /*重载右--运算符*/
    Time operator--(int);

    /*重载减法运算符*/
    int operator-(const Time& time) const;

    /*重载重定向输出运算符*/
    friend ostream& operator<<(ostream& Stream, const Time& aTime);

    /*重载重定向输入运算符*/
    friend istream& operator>>(istream& Stream, Time& aTime);

private:
    /*私有成员变量*/
    unsigned int m_uHour;
    unsigned int m_uMinute;
    unsigned int m_uSecond;
};

#endif // MYTIME_H
