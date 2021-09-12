/*************************************************************************
【文件名】                 （user.cpp)
【功能模块和目的】         （定义user类的成员函数)
【开发者及日期】           （范静涛 2021.7.29))
*************************************************************************/
#include "message.h"
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <memory>

using namespace std;
/*定义由Message类对象组成的矢量模板m_All*/
vector<shared_ptr<Message>> Message::m_All{};
/*************************************************************************
【类名】             （Garbo_2)
【功能】             （先于父类析构,调用SaveToFile保存用户信息到文件)
【接口说明】         （构造函数Garbo_2,析构函数~Garbo_2)
【开发者及日期】     （洪宇睿 2021.8.2 参考范静涛2021.7.29的同构函数)
*************************************************************************/
class Garbo_2
{
public:
    ~Garbo_2();
};
/*************************************************************************
【函数名称】       （~Garbo)
【函数功能】       （析构函数,将m_All中的用户信息保存到"Messages.txt")
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.2 参考范静涛2021.7.29的同构函数)
*************************************************************************/
Garbo_2::~Garbo_2() {
    Message::SaveToFile("Messages.txt");
}
/*实例化一个Garbo类对象以触发析构函数*/
Garbo_2 garbo_2;
/*************************************************************************
【函数名称】       （Message)
【函数功能】       （构造函数,向用户列表中添加一条新信息排序、查找、组织输出文本
                    ,并有异常处理功能)
【参数】           （常引用的日期、时间对象,表示标签和内容的字符串)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.2)
【修改记录】       （洪宇睿 2021.8.7 把参数由年月日时分秒改为日期时间对象)
*************************************************************************/
Message::Message(Date& date, Time& time,
                 string& type, string& contents)
                 : strType(m_Type),strContents(m_Contents), strFormat(m_Format) {
    m_Date = date;
    m_Time = time;
    m_Type = type;
    m_Contents = contents;
    m_Format = to_string(date.uYear) + "." + to_string(date.uMonth) + "."
             + to_string(date.uDay) + " " + to_string(time.uHour) + ":"
             + to_string(time.uMinute) + ":" + to_string(time.uSecond) + " ["
             + type + "] " + contents
             + "\n--------------------------------------------------------"
               "------------------------------------------------------\n";
}
/*************************************************************************
【函数名称】       （~Message)
【函数功能】       （析构函数)
【参数】           （空)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.2)
*************************************************************************/
Message::~Message() {

}
/*************************************************************************
【函数名称】       （OutputToStream)
【函数功能】       （将用户名和密码输出重定向到指定流中)
【参数】           （输出流)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.2 参考范静涛2021.7.29的同构函数)
*************************************************************************/
void Message::OutputToStream(ostream& Stream) const {
    Stream << m_Date << " " << m_Time << " " << m_Type << endl << m_Contents
           << endl << "eοf" <<endl;
}     /*这里不是'o',而是希腊字母'ο',防止误输,也可用复杂极不可能重合的字符串代替*/
/*************************************************************************
【函数名称】       （SaveToFile)
【函数功能】       （将m_All中的所有用户名和密码输入指定文件)
【参数】           （文件名字符串)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.2 参考范静涛2021.7.29的同构函数)
*************************************************************************/
void Message::SaveToFile(const string& FileName) {
    ofstream File(FileName);
    if (!File.is_open()) {
        throw invalid_argument("Can't Create File : " + FileName);
    }
    auto Saver = [&File](shared_ptr<Message> Ptr) {Ptr->OutputToStream(File);};
    File << m_All.size() << endl;
    for_each(m_All.begin(), m_All.end(),Saver);
    File.close();
}
/*************************************************************************
【函数名称】       （LinkAll)
【函数功能】       （将指定类型的全部Messge对象中的全部字符串信息打包形成格式化文本)
【参数】           （言/行/念/全部标签的字符串)
【返回值】         （字符串,应显示在框内的所有文本)
【开发者及日期】   （洪宇睿 2021.8.2)
*************************************************************************/
string Message::LinkAll(string type) {
    string text = "";
    for (auto it : m_All) {
        if (it->m_Type == type || type == "全部")
         text += it->m_Format;
    }
    return text;
}
/*************************************************************************
【函数名称】       （LoadFromFile)
【函数功能】       （从指定文件输入现有用户数量和所有用户名和密码信息)
【参数】           （文件名字符串)
【返回值】         （User类对象指针)
【开发者及日期】   （洪宇睿 2021.8.2 参考范静涛2021.7.29的类似函数)
*************************************************************************/
void Message::LoadFromFile(const string& FileName) {
    ifstream File(FileName);
    if (!File.is_open()) {
        throw invalid_argument("File Not Exist: " + FileName);
    }
    unsigned long MessageCount;
    File >> MessageCount;
    File.get();
    Date date;
    Time time;
    string type;
    string line;
    string contents;
    for (unsigned long i = 0; i < MessageCount; i++) {
        line = "";
        File >> date >> time >> type;
        getline(File, contents); /*去除换行符*/
        /*为了防止用户无意输入eof,此处的'o'是希腊字母'ο'*/
        getline(File, contents); /*开始读入内容*/
        while (true) {
            contents += line;
            getline(File, line);
            if (line == "eοf") {
                break;
            }
            contents += "\n";
        }
        Message* pMessage = new
            Message(date, time, type, contents);
        m_All.push_back(shared_ptr<Message>(pMessage));
    }
    File.close();
}
/*************************************************************************
【函数名称】       （InsertMessage)
【函数功能】       （根据新消息的日期时间信息,在消息序列的合适位置构造之)
【参数】           （短整型年月日时分秒,言/行/念标签和文本内容字符串)
【返回值】         （空)
【开发者及日期】   （洪宇睿 2021.8.5)
*************************************************************************/
void Message::InsertMessage(Date& date, Time& time,
                            string& type, string& contents) {
    shared_ptr<Message> message(
        new Message(date, time, type, contents));
    bool flag = true;
    for (auto it = Message::m_All.begin(); it != Message::m_All.end(); it++) {
        if (date < (*it)->m_Date
            || (date == (*it)->m_Date && time < (*it)->m_Time)) {
            Message::m_All.insert(it, message);
            flag = false;
            break;
        }
    }
    if (flag) {
        Message::m_All.insert(Message::m_All.end(), message);
    }
}
/*************************************************************************
【函数名称】       （SelectMessages)
【函数功能】       （根据需求的消息类型和时间范围,返回待输出的全部文本)
【参数】           （分别指向始末Date类对象的指针,言/行/念标签字符串)
【返回值】         （字符串,为待在窗口显示的全部文本信息)
【开发者及日期】   （洪宇睿 2021.8.5)
*************************************************************************/
string Message::SelectMessages(Date date1, Date date2, string type)
{
    string text = "";
    if (type != "全部") {
        for (auto it = Message::m_All.begin();
             (it != Message::m_All.end() && date2 >= (*it)->m_Date); it++) {
            if (date1 <= (*it)->m_Date && (*it)->strType == type) {
                text += (*it)->strFormat;
            }
        }
    }
    else {
        for (auto it = Message::m_All.begin();
             (it != Message::m_All.end() && (date2 >= (*it)->m_Date)); it++) {
            if (date1 <= (*it)->m_Date) {
                text += (*it)->strFormat;
            }
        }
    }
    return text;
}
