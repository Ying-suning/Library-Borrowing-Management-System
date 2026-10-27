#include "Book.h"

Book::Book() : Resource("1495584", "C++程序设计", true)
{
    m_author = "晓晓";
    m_isbn = "978-7-111-24212-3";
    m_publisher = "人民邮电出版社";
    m_price = 59.0;
    m_stock = 1;
}

Book::Book(string na, string au, string isbn, string id, string pu, double pr, int stock)
    : Resource(id, na, stock > 0), m_author(au), m_isbn(isbn), m_publisher(pu), m_price(pr), m_stock(stock)
{
}

double Book::getprice() const { return m_price; }
void Book::setprice(double pr) { m_price = pr; }
int Book::getStock() const { return m_stock; }

void Book::setStock(int s)
{
    if (s < 0) s = 0;
    m_stock = s;
    m_state = (m_stock > 0);
}

bool Book::borrowResource()
{
    if (m_stock > 0)
    {
        m_stock--;
        m_state = (m_stock > 0);
        return true;
    }
    return false;
}

void Book::returnResource()
{
    m_stock++;
    m_state = true;
}

void Book::showInfo() const
{
    cout << "书名：" << m_name << endl;
    cout << "作者：" << m_author << endl;
    cout << "ISBN：" << m_isbn << endl;
    cout << "编号：" << m_id << endl;
    cout << "出版社：" << m_publisher << endl;
    cout << "价格：" << m_price << endl;
    cout << "库存：" << m_stock << " 本" << endl;
    cout << "状态：" << (m_state ? "在馆" : "已借完") << endl;
}