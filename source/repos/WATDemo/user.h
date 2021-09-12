/*************************************************************************
【文件名】                 （user.h)
【功能模块和目的】         （声明可重用的User类)
【开发者及日期】           （范静涛 2021.7.29)
*************************************************************************/
#ifndef USER_H
#define USER_H

#include "CipherText.hpp"
#include <vector>
#include <memory>

using namespace std;

class Administrator;
/*************************************************************************
【类名】             （User)
【功能】             （实现可复用的User类)
【接口说明】         （判断是否为管理员的IsAdministrator函数,重定向函数
                     OutputToStream,文件格式化输入输出函数LoadFromFile,
                     SaveToFile,验证登录的函数Verify)
【开发者及日期】     （范静涛 2021.7.29)
*************************************************************************/
class User
{
public:
    /*由于需要严格控制User对象的产生,默认、拷贝构造函数及重载赋值运算符需删除*/
    User() = delete;

    /*析构函数*/
    virtual ~User();

    User(const User&) = delete;

    User& operator=(const User&) = delete;

    /*返回是否为管理员的结果*/
    virtual bool IsAdministrator() const;

    /*输出到指定流*/
    void OutputToStream(ostream& Stream) const;

    /*保存到指定文件*/
    static void SaveToFile(const string& FileName);

    /*从指定文件输入*/
    static User* LoadFromFile(const string& FileName);

    /*遍历用户容器验证登录,返回匹配用户的指针*/
    static shared_ptr<User> Verify(const string& Name, const string& Password);

protected:
    /*保护的构造函数,防止随意调用*/
    User(const string& Name, const CipherText& Password);

    /*通过 用户名字符串和密文密码新建用户*/
    virtual void AddUser(const string& Name, const CipherText& Password);

private:
    /*用户名字符串*/
    string m_Name;

    /*密文密码*/
    CipherText m_Password;

    /*智能指针用户容器,配合User类的派生*/
    static vector<shared_ptr<User>> m_All;

    /*判断容器是否为空*/
    static bool IsExist(const string& Name);
};

#endif // USER_H
