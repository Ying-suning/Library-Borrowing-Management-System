#include "BookMall.h"
#include <iostream>
using namespace std;

BookMall::BookMall() :m_bookCount(0), m_stuCount(0) {}

//添加图书
void BookMall::addBook(const Book& b)
{
    if (m_bookCount >= 20)
    {
        cout << "图书馆图书已满！" << endl;
        return;
    }
    m_books[m_bookCount++] = b;
}

//展示所有图书
void BookMall::showAllBooks() const
{
    cout << "\n======== 图书馆全部图书 ========" << endl;
    for (int i = 0; i < m_bookCount; i++)
    {
        cout << "--- 第" << i + 1 << "本书 ---" << endl;
        m_books[i].showInfo();
    }
}

//加学生
void BookMall::addStudent(const Student& s)
{
    if (m_stuCount >= 10)
    {
        cout << "图书馆学生名额已满！" << endl;
        return;
    }
    m_stus[m_stuCount++] = s;
}

//展示所有学生
void BookMall::showAllStudents() const
{
    cout << "\n======== 所有学生 ========" << endl;
    for (int i = 0; i < m_stuCount; i++)
    {
        cout << "--- 第" << i + 1 << "个学生 ---" << endl;
        m_stus[i].showStudentInfo();
    }
}

//学号找对应学生
Student* BookMall::findStudentById(const string& id)
{
    for (int i = 0; i < m_stuCount; i++)
    {
        if (m_stus[i].getId() == id)
        {
            return &m_stus[i];
        }
    }
    return nullptr;
}

//用图书编号找书
Book* BookMall::findBookById(const string& bookId)
{
    for (int i = 0; i < m_bookCount; i++)
    {
        if (m_books[i].getId() == bookId)
        {
            return &m_books[i];
        }
    }
    return nullptr;
}

//借书
bool BookMall::borrowBook(const string& stuId, const string& bookId)
{
    Student* pStu = findStudentById(stuId);
    Book* pBook = findBookById(bookId);
    if (pStu == nullptr)
    {
        cout << "借书失败：不存在该学生！" << endl;
        return false;
    }
    if (pBook == nullptr)
    {
        cout << "借书失败：不存在该图书！" << endl;
        return false;
    }
    return pStu->borrowBook(*pBook);
}

//还书
bool BookMall::returnBook(const string& stuId, const string& bookId)
{
    Student* pStu = findStudentById(stuId);
    Book* pBook = findBookById(bookId);
    if (pStu == nullptr)
    {
        cout << "还书失败：不存在该学生！" << endl;
        return false;
    }
    if (pBook == nullptr)
    {
        cout << "还书失败：不存在该图书！" << endl;
        return false;
    }
    return pStu->returnBook(*pBook);
}


//增加图书数量
bool BookMall::addBookCount(const string& bookId, int addNum)
{
    Book* pBook = findBookById(bookId);
    if (pBook == nullptr)
    {
        cout << "增加数量失败：图书不存在！" << endl;
        return false;
    }
    cout << "图书数量增加成功！" << endl;
    return true;
}


//减少图书数量
bool BookMall::subBookCount(const string& bookId, int subNum)
{
    Book* pBook = findBookById(bookId);
    if (pBook == nullptr)
    {
        cout << "减少数量失败：图书不存在！" << endl;
        return false;
    }
    return true;
}

//删除指定图书
bool BookMall::delBook(const string& bookId)
{
    int index = -1;
    for (int i = 0; i < m_bookCount; i++)
    {
        if (m_books[i].getId() == bookId)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "删除失败，未找到该图书！" << endl;
        return false;
    }
    for (int i = index; i < m_bookCount - 1; i++)
    {
        m_books[i] = m_books[i + 1];
    }
    m_bookCount--;
    cout << "图书删除成功！" << endl;
    return true;
}
