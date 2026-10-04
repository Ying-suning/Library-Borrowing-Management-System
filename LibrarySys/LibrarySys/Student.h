#pragma once
#include <string>
class Book; 
class Student
{
private:
    std::string m_id;
    std::string m_name;
    int m_borrowCnt;
public:
    Student();
    Student(std::string id, std::string name);
    std::string getId();

    bool borrowBook(Book& book);
    bool returnBook(Book& book);

    void showStudent() const;
    int getBorrowCnt();
};

