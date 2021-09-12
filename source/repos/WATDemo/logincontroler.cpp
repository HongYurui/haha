/*************************************************************************
【文件名】                 （logincontroler.cpp)
【功能模块和目的】         （控制器类,实现用户登录功能)
【开发者及日期】           （范静涛 2021.7.29)
*************************************************************************/
#include "logincontroler.h"
#include "addusercontroler.h"
#include "message.h"
/*初始化成员指针*/
Administrator* LoginControler::pAdmin = nullptr;
/*************************************************************************
【函数名称】       （LoginControler)
【函数功能】       （构造函数,在程序运行开始时构造LoginWindow,读入用户和消息信息)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
【修改记录】        （洪宇睿 2021.8.2 加入消息信息的读取)
*************************************************************************/
LoginControler::LoginControler() {
    pAdmin = (Administrator*)User::LoadFromFile("Users.txt");
    Message::LoadFromFile("Messages.txt");
}
/*************************************************************************
【函数名称】       （~LoginControler)
【函数功能】       （析构函数)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
LoginControler::~LoginControler() {

}
/*************************************************************************
【函数名称】       （SetpAdmin)
【函数功能】       （传递私有指针变量pAdmin)
【参数】           （空)
【返回值】         （指向Administrator类对象的指针pAdmin)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
Administrator* LoginControler::SetpAdmin() {
    return pAdmin;
}
/*************************************************************************
【函数名称】       （Login)
【函数功能】       （登录)
【参数】           （两个常引用字符串,为使用者输入的用户名和密码明文)
【返回值】         （枚举类LoginResult中的异常状态)
【开发者及日期】   （范静涛 2021.7.29)
*************************************************************************/
LoginResult LoginControler::Login(const string& strName,
                                  const string& strPassword) const {
    if (strName == "") {
        return LoginResult::EMPTY_NAME;
    }
    else if (strPassword == "") {
        return LoginResult::EMPTY_PASSWORD;
    }
    try {
        shared_ptr<User> LoginedUser = User::Verify(strName, strPassword);
        if (LoginedUser->IsAdministrator()) {
            return LoginResult::ADMIN_LOGINED;
        }
        else {
            return LoginResult::USER_LOGINED;
        }
    } catch (invalid_argument e) {
        if (e.what() == string("No such user.")) {
            return LoginResult::NO_USER;
        }
        else {
            return LoginResult::WRONG_PASSWORD;
        }
    }
}
