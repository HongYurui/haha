/*************************************************************************
【文件名】                 （logincontroler.h)
【功能模块和目的】         （控制器类,声明LoginControler类)
【开发者及日期】           （范静涛 2021.7.29)
*************************************************************************/
#ifndef LOGINCONTROLER_H
#define LOGINCONTROLER_H

#include "administrator.h"
/*************************************************************************
【类名】             （LoginResult)
【功能】             （枚举类,存储登录异常信息以控制登录窗口)
【接口说明】         （枚举常量ADMIN_LOGINED(管理员登录),USER_LOGINED(用户登录),
                      NO_USER(无用户信息),WRONG_PASSWORD(密码错误))
【开发者及日期】     （范静涛 2021.7.29)
*************************************************************************/
enum class LoginResult
{
    EMPTY_NAME,
    EMPTY_PASSWORD,
    ADMIN_LOGINED,
    USER_LOGINED,
    NO_USER,
    WRONG_PASSWORD,
};
/*************************************************************************
【类名】             （LoginControler)
【功能】             （控制器类,实现用户登录窗口的控制器)
【接口说明】         （构造函数LoginControler)
【开发者及日期】     （范静涛 2021.7.29)
*************************************************************************/
class LoginControler
{
public:
    /*构造函数*/
    LoginControler();

    /*析构函数*/
    ~LoginControler();

    /*登录函数,返回用户登录的结果*/
    LoginResult Login(const string& strName, const string& strPassword) const;

    /*静态函数,传递管理员对象的指针*/
    static Administrator* SetpAdmin();

private:
    /*静态变量,管理员对象的指针*/
    static Administrator* pAdmin;
};

#endif // LOGINCONTROLER_H
