/*************************************************************************
【函数名称】     （AddUserControler)
【函数功能】     （构造函数,调用SetpAdmin给成员指针pAdmin赋值,使其指向管理员对象)
【参数】         （空)
【返回值】       （空)
【开发者及日期】 （洪宇睿 2021.7.31)
*************************************************************************/
#include "addusercontroler.h"
#include "logincontroler.h"
/*初始化AddUserControler类中指向Administrator类的成员指针*/
Administrator* AddUserControler::pAdmin = nullptr;
/*************************************************************************
【函数名称】     （AddUserControler)
【函数功能】     （构造函数,调用SetpAdmin给成员指针pAdmin赋值,使其指向管理员对象)
【参数】         （空)
【返回值】       （空)
【开发者及日期】 （洪宇睿 2021.7.31)
*************************************************************************/
AddUserControler::AddUserControler() {
    pAdmin = LoginControler::SetpAdmin();
}
/*************************************************************************
【函数名称】     （~AddUserControler)
【函数功能】     （析构函数)
【参数】         （空)
【返回值】       （空)
【开发者及日期】 （洪宇睿 2021.7.31)
*************************************************************************/
AddUserControler::~AddUserControler() {

}
/*************************************************************************
【函数名称】       （AddUser)
【函数功能】       （调用管理员对象的AddUser方法向列表中添加用户,并有异常处理)
【参数】           （新用户的用户名和密码明文字符串)
【返回值】         （AddUserResult枚举类中的数值,表示添加的结果)
【开发者及日期】   （洪宇睿 2021.7.31)
*************************************************************************/
AddUserResult AddUserControler::AddUser(const string& strName,
                                        const string& strPassword) const {
    if (strName == "") {
        return AddUserResult::EMPTY_NAME;
    }
    else if (strPassword == "") {
        return AddUserResult::EMPTY_PASSWORD;
    }
    try {
        pAdmin->AddUser(strName,              /*加密过程*/
            CipherText::MakeFromCipherText(MD5::Encrypt(strPassword)));
    }
    catch (invalid_argument e) {
        if (e.what() == string("Administrator exists.")) {
            return AddUserResult::ADMIN_EXISTED;
        }
        else if (e.what() == string("Duplicate username")) {
            return AddUserResult::NAME_USED;
        }
    }
    return AddUserResult::ADDUSER_SUCCEEDED;  /*AddUser窗口根据添加结果进行操作*/
}
