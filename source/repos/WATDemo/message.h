/*************************************************************************
【文件名】                 （message.h)
【功能模块和目的】         （声明可复用的message类)
【开发者及日期】           （洪宇睿 2021.8.2)
*************************************************************************/
#ifndef MESSAGE_H
#define MESSAGE_H

#include "date.h"
#include "mytime.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;
/*************************************************************************
【类名】             （Message)
【功能】             （实现包括日期、时间、言/行/念标签、文本内容的可复用消息类)
【接口说明】         （常引用日期时间类,字符串言/行/念标签,文本内容,格式化
                      输出文本,构造函数Message,重定向函数OutputToStream
                     ,文件格式化输入输出函数LoadFromFile,SaveToFile,插入、筛选
                    、组织消息函数InsertMessage,SelectMessages和LinkAll)
【开发者及日期】     （洪宇睿 2021.8.2)
【修改记录】          （洪宇睿 2021.8.7 把成员变量由年月日时分秒修改为Date和Time
                    两类的成员,实现了复用,修改了使用相应变量的函数)
*************************************************************************/
class Message
{
public:
    /*常引用的言/行/念类型标签字符串*/
    const string& strType;

    /*常引用的消息内容字符串*/
    const string& strContents;

    /*常引用的格式化文本字符串*/
    const string& strFormat;

    /*由于需要严格控制Message对象的产生,默认、拷贝构造函数及重载赋值运算符需删除*/
    Message() = delete;

    /*析构函数*/
    ~Message();

    Message(const Message&) = delete;

    Message& operator=(const Message&) = delete;

    /*构造函数，以日期、时间、标签、内容和格式控制组合形成信息类对象*/
    Message(Date& date, Time& time,
            string& type, string& contents);

    /*输出到指定流*/
    void OutputToStream(ostream& Stream) const;

    /*保存到指定文件*/
    static void SaveToFile(const string& FileName);

    /*从指定文件输入*/
    static void LoadFromFile(const string& FileName);

    /*在序列的合理位置新建新消息*/
    static void InsertMessage(Date& date, Time& time,
                              string& type, string& contents);

    /*搜索标签和日期符合要求的消息*/
    static string SelectMessages(Date date1, Date date2, string type);

    /*连接特定的字符串,形成全部文本,并返回*/
    static string LinkAll(string type);

private:
    /*分别为日期类、时间类,字符串型标签类型、内容、格式化输出文本成员*/
    Date m_Date;
    Time m_Time;
    string m_Type;
    string m_Contents;
    string m_Format;

    /*静态容器,存放所有的消息类对象*/
    static vector<shared_ptr<Message>> m_All;
};

#endif // MESSAGE_H
