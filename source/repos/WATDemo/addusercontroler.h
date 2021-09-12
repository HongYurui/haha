/*************************************************************************
【文件名】                 （addusercontroler.h)
【功能模块和目的】         （控制器,声明控制用户管理窗口的控制器)
【开发者及日期】           （洪宇睿 2021.7.31)
*************************************************************************/
#ifndef ADDUSERCONTROLER_H
#define ADDUSERCONTROLER_H

#include "administrator.h"
/*************************************************************************
【类名】             （AddUserResult)
【功能】             （枚举类,表示AddUser的操作结果)
【接口说明】         （默认构造函数,析构函数,控制用户添加的AddUser)
【开发者及日期】     （洪宇睿 2021.7.31)
*************************************************************************/
enum class AddUserResult
{
    EMPTY_NAME,
    EMPTY_PASSWORD,
    ADMIN_EXISTED,
    ADDUSER_SUCCEEDED,
    NAME_USED,
};
/*************************************************************************
【类名】             （AddUserControler)
【功能】             （控制用户管理窗口添加用户的结果)
【接口说明】         （默认构造函数,析构函数,控制用户添加的AddUser)
【开发者及日期】     （洪宇睿 2021.7.31)
*************************************************************************/
class AddUserControler
{
public:
    /*构造函数*/
    AddUserControler();

    /*析构函数*/
    ~AddUserControler();

    /*添加用户函数*/
    AddUserResult AddUser(const string& Name, const string& Password) const;

private:
    /*指向管理员的指针*/
    static Administrator* pAdmin;
};

#endif // ADDUSERCONTROLER_H
