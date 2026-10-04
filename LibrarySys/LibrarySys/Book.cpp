#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() : Resource("1495584", "C++程序设计")
{
    m_author = "晓晓";
    m_isbn = "978-7-111-24212-3";
    m_publisher = "人民邮电出版社";
    m_price = 59.0;
    m_state = true;
}

Book::Book(string na, string au, string isbn, string id, string pu, double pr, bool state)
    : Resource(id, na), m_author(au), m_isbn(isbn), m_publisher(pu), m_price(pr), m_state(state)
{
}

double Book::getprice() const
{
    return m_price;
}

void Book::setprice(double pr)
{
    m_price = pr;
}

bool Book::getBorrowState() const
{
    return m_state;
}

void Book::setBorrowState(bool st)
{
    m_state = st;
}

void Book::showInfo() const
{
    cout << "书名：" << m_name << endl;
    cout << "作者：" << m_author << endl;
    cout << "ISBN：" << m_isbn << endl;
    cout << "编号：" << m_id << endl;
    cout << "出版社：" << m_publisher << endl;
    cout << "价格：" << m_price << endl;
    if (m_state)
        cout << "状态：在馆" << endl;
    else
        cout << "状态：已借出" << endl;
}
