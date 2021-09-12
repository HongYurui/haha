/*************************************************************************
【文件名】                 （Administrator.h)
【功能模块和目的】         （声明Administrator类)
【开发者及日期】           （洪宇睿 2021.7.31)
*************************************************************************/
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include "CipherText.hpp"
#include <string>

using namespace std;

class User;
/*************************************************************************
【类名】             （Administrator)
【功能】             （可复用类,继承User类,实现有添加用户功能的用户（管理员))
【接口说明】         （指向自身类对象的指针pAdministrator,默认构造函数,
                      带一个参数的构造函数,判断是否为管理员的
                      重写函数IsAdministrator, 添加新用户的AddUser函数)
【开发者及日期】     （洪宇睿 2021.7.31)
*************************************************************************/
class Administrator : public User
{
public:
    /*默认构造函数*/
    Administrator();

    /*析构函数*/
    ~Administrator();

    /*删除拷贝构造函数*/
    Administrator(const Administrator&) = delete;

    /*删除重载赋值运算符*/
    Administrator& operator=(const Administrator&) = delete;

    /*仅带密文密码参数的构造函数*/
    Administrator(const CipherText& Password);

    /*判断是否为管理员,重写*/
    bool IsAdministrator() const override;

    /*以用户名字符串和密文密码添加新用户*/
    void AddUser(const string& Name, const CipherText& Password) override;
};

#endif // ADMINISTRATOR_H
