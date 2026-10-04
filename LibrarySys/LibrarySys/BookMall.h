#ifndef BOOKMALL_H
#define BOOKMALL_H

#include "Student.h"
#include "Book.h"
#include <string>
#include <vector>

const int MAX_BOOKS = 20;   
const int MAX_STUS = 10;  

class BookMall
{
private:
    Book m_books[MAX_BOOKS];
    Student m_stus[MAX_STUS];
    int m_bookCount;
    int m_stuCount;
public:
    BookMall();
    void addBook(const Book& b);
    void showAllBooks() const;
    void addStudent(const Student& s);
    void showAllStudents() const;

    Student* findStudentById(const std::string& id);
    Book* findBookById(const std::string& bookId);
    bool borrowBook(const std::string& stuId, const std::string& bookId);
    bool returnBook(const std::string& stuId, const std::string& bookId);
    void showAvailableByVector() const;
};

#endif
