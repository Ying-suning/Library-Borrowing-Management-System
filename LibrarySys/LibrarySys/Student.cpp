#include "Student.h"
#include "Book.h"
#include <iostream>
using namespace std;

Student::Student()
{
    m_id = "5120250001";
    m_name = "小红";
    m_borrowCnt = 0;
}

Student::Student(string id, string name)
{
    m_id = id;
    m_name = name;
    m_borrowCnt = 0;
}

bool Student::borrowBook(Book& book)//借书
{
    if (m_borrowCnt >= 3)
    {
        cout << m_name << "借书失败！已达到最大借书数量3本" << endl;
        return false;
    }
    if (book.getstate() == true)
    {
        book.setstate(false);
        m_borrowCnt++;
        cout << m_name << "借书成功！" << endl;
        return true;
    }
    else
    {
        cout << "借书失败: 该书已经被借出！" << endl;
        return false;
    }
}


bool Student::returnBook(Book& book)//还书
{
    if (m_borrowCnt <= 0)
    {
        cout << m_name << "还书失败！该学生没有借阅任何图书" << endl;
        return false;
    }
    if (book.getstate() == false)
    {
        book.setstate(true);
        m_borrowCnt--;
        cout << m_name << "还书成功！" << endl;
        return true;
    }
    else
    {
        cout << "还书失败：该书未借出！" << endl;
        return false;
    }
}

void Student::showStudent() const
{
    cout << "学号：" << m_id << endl;
    cout << "姓名：" << m_name << endl;
    cout << "已借数量：" << m_borrowCnt << endl;
}

int Student::getBorrowCnt()//已借书数量
{
    return m_borrowCnt;
}
string Student::getId()
{
    return m_id;
}
