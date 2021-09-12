//
//  CipherText.hpp
//  DEMO_DAY_04_USER_XCODE
//
//  Created by Jingtao Fan on 2021/7/29.
//
/*************************************************************************
【文件名】                 （CipherText.hpp)
【功能模块和目的】         （声明CipherText加密文本类)
【开发者及日期】           （范静涛 2021.7.29)
*************************************************************************/
#ifndef CipherText_hpp
#define CipherText_hpp

#include "MD5.hpp"
#include <ostream>

using namespace std;
/*************************************************************************
【类名】             （CipherText)
【功能】             （可复用类,MD5的派生类,实现密文的生成、赋值、比较、重定向)
【接口说明】         （构造函数,析构函数,重载赋值、比较、重定向运算符,CipherText
                      类对象生成函数MakeFromCipherText)
【开发者及日期】     （洪宇睿 2021.7.31)
*************************************************************************/
class CipherText : public MD5 {
public:
    /*默认构造函数，文本无内容*/
    CipherText();

    /*构造函数，得到字符串MD5加密后的密文作为成员*/
    CipherText(const string& Plainext);

    /*析构函数*/
    ~CipherText();

    /*重载等于运算符*/
    bool operator==(const string& Plaintext) const;

    /*重载不等于运算符*/
    bool operator!=(const string& Plaintext) const;

    /*重载赋值运算符*/
    CipherText operator=(const string& Plaintext);

    /*重载重定向输出运算符*/
    friend ostream& operator<<(ostream& stream, const CipherText& CipherText);

    /*用字符串给CipherText对象成员赋值*/
    static CipherText MakeFromCipherText(const string& CipherText);
};
//using CipherText = string;

#endif /* CipherText_hpp */
