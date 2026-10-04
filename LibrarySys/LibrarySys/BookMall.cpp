#include "BookMall.h"
#include <iostream>
using namespace std;


BookMall::BookMall() :m_bookCount(0), m_stuCount(0){}

void BookMall::addBook(const Book& b)//添加图书
{
    if (m_bookCount >= 20)
    {
        cout << "图书馆图书已满！" << endl;
        return;
    }
    m_books[m_bookCount++] = b;
}

void BookMall::showAllBooks() const//展示所有图书
{
    cout << "\n======== 图书馆全部图书 ========" << endl;
    for (int i = 0; i < m_bookCount; i++)
    {
        cout << "--- 第" << i + 1 << "本书 ---" << endl;
        m_books[i].showBook();
    }
}

void BookMall::addStudent(const Student& s)//加学生
{
    if (m_stuCount >= 10)
    {
        cout << "图书馆学生名额已满！" << endl;
        return;
    }
    m_stus[m_stuCount++] = s;
}

void BookMall::showAllStudents() const//展示所有学生
{
    cout << "\n======== 所有学生 ========" << endl;
    for (int i = 0; i < m_stuCount; i++)
    {
        cout << "--- 第" << i + 1 << "个学生 ---" << endl;
        m_stus[i].showStudent();
    }
}

Student* BookMall::findStudentById(const string& id)//学号找对应学生
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

Book* BookMall::findBookById(const string& bookId)//用图书编号找书
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

void BookMall::showAvailableByVector() const//特色功能
{
    vector<Book> tempVec;
    for (int i = 0; i < m_bookCount; i++)
    {
        tempVec.push_back(m_books[i]);
    }
    cout << "\n====特色功能====\n";
    for (const auto& book : tempVec)
    {
        if (book.getstate()) 
        {
            book.showBook();
        }
    }
}

