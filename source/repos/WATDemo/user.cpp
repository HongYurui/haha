/*************************************************************************
【文件名】                 （user.cpp)
【功能模块和目的】         （定义User类的成员函数)
【开发者及日期】           （范静涛 2021.7.29))
*************************************************************************/
#include "administrator.h"
#include <string>
#include <stdexcept>
#include <algorithm>
#include <fstream>

using namespace std;
/*定义由User类对象组成的矢量模板m_All*/
vector<shared_ptr<User>> User::m_All{};
/*************************************************************************
【类名】             （Garbo)
【功能】             （先于父类析构,调用SaveToFile保存用户信息到文件)
【接口说明】         （构造函数Garbo,析构函数~Garbo)
【开发者及日期】     （范静涛 2021.7.29)
*************************************************************************/
class Garbo
{
public:
    ~Garbo();
};
/*************************************************************************
【函数名称】       （~Garbo)
【函数功能】       （析构函数,将m_All中的用户信息保存到"User.txt")
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
Garbo::~Garbo() {
    User::SaveToFile("Users.txt");
}
/*实例化一个Garbo类对象以触发析构函数*/
Garbo garbo;
/*************************************************************************
【函数名称】       （User)
【函数功能】       （构造函数,向用户列表中添加一个新用户,并有异常处理功能)
【参数】           （两个常引用字符串,分别为明文用户名和密文密码)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
User::User(const string& Name, const CipherText& Password)
        : m_Password(Password) {
    auto Finder = [&Name](shared_ptr<User> ptr)
        ->bool {return (ptr->m_Name == Name);};
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    if (it != m_All.end()) {
        if ((*it)->IsAdministrator()) {
            throw invalid_argument("Administrator exists.");
        }
        else {
            throw invalid_argument("Duplicate username");
        }
    }
    m_Name = Name;
    m_All.push_back(shared_ptr<User>(this));
}
/*************************************************************************
【函数名称】       （AddUser)
【函数功能】       （以常引用的用户名和密码字符串构造一个新的用户类对象)
【参数】           （两个常引用字符串,分别为明文用户名和密文密码)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
void User::AddUser(const string& Name, const CipherText& Password) {
    new User(Name, Password);
}
/*************************************************************************
【函数名称】       （~AddUser)
【函数功能】       （析构函数)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
User::~User() {

}
/*************************************************************************
【函数名称】       （IsExist)
【函数功能】       （判断并返回某一用户名是否存在)
【参数】           （常引用字符串,为明文用户名)
【返回值】         （布尔值,是否为管理员的判断结果)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
bool User::IsExist(const string& Name) {
    auto Finder = [&Name](shared_ptr<User> ptr)
        ->bool {return (ptr->m_Name == Name);};
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    return (it != m_All.end());
}
/*************************************************************************
【函数名称】       （IsAdministrator)
【函数功能】       （判断并返回User类对象是否为管理员)
【参数】           （空)
【返回值】         （布尔值,是否为管理员的判断结果)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
bool User::IsAdministrator() const {
    return false;
}
/*************************************************************************
【函数名称】       （OutputToStream)
【函数功能】       （将用户名和密码输出重定向到指定流中)
【参数】           （输出流)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
void User::OutputToStream(ostream& Stream) const {
    Stream << m_Name << endl << m_Password << endl;
}
/*************************************************************************
【函数名称】       （SaveToFile)
【函数功能】       （将m_All中的所有用户名和密码输入指定文件)
【参数】           （文件名字符串)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
void User::SaveToFile(const string& FileName) {
    ofstream File(FileName);
    if (!File.is_open()) {
        throw invalid_argument("Can't Create File : " + FileName);
    }
    auto Saver = [&File](shared_ptr<User> Ptr) {Ptr->OutputToStream(File);};
    File << m_All.size() << endl;
    for_each(m_All.begin(), m_All.end(),Saver);
    File.close();
}
/*************************************************************************
【函数名称】       （LoadFromFile)
【函数功能】       （从指定文件输入现有用户数量和所有用户名和密码信息)
【参数】           （文件名字符串)
【返回值】         （User类对象指针)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
User* User::LoadFromFile(const string& FileName) {
    Administrator* pAdmin;
    ifstream File(FileName);
    if (!File.is_open()) {
        throw invalid_argument("File Not Exist: " + FileName);
    }
    unsigned long UserCount;
    File >> UserCount;
    File.get();
    if (UserCount <= 1) {
        pAdmin = new Administrator();
    }
    else {
        string Name;
        string Password;
        getline(File, Name);
        getline(File, Password);
        pAdmin = new Administrator(CipherText::MakeFromCipherText(Password));

        for (unsigned long i = 0; i < UserCount - 1; i++) {
            getline(File, Name);
            getline(File, Password);
            new User(Name, CipherText::MakeFromCipherText(Password));
        }
    }
   File.close();
   return pAdmin;
}
/*************************************************************************
【函数名称】       （Verify)
【函数功能】       （登录并返回登录的用户,有异常处理)
【参数】           （两个常引用字符串,为使用者输入的用户名和密码)
【返回值】         （智能指针User类对象)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
shared_ptr<User> User::Verify(const string& Name, const string& Password) {
    auto Finder = [&Name](shared_ptr<User> ptr)
        ->bool {return (ptr->m_Name == Name);};
    auto it = find_if(m_All.begin(), m_All.end(), Finder);
    if (it == m_All.end()) {
        throw invalid_argument("No such user.");
    }
    else if ((*it)->m_Password != Password) {
        throw invalid_argument("Wrong password.");
    }
    else {
        return *it;
    }
}
