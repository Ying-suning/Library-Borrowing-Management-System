#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Book.h"
using namespace std;

class Student {
private:
    string stuId;
    string stuName;
    int borrowCount; 
public:
    Student() = default;
    Student(string id, string name);
    string getStuId() const;
    string getId() const { return getStuId(); }
    int getBorrowCount() const;
    bool borrowBook(Book& book);
    bool returnBook(Book& book);
    void showStudentInfo() const;
};
#endif
