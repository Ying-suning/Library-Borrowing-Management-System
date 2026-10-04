#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string id, string name) :stuId(id), stuName(name), borrowCount(0) {}

string Student::getStuId() const {
    return stuId;
}

int Student::getBorrowCount() const {
    return borrowCount;
}

bool Student::borrowBook(Book& book) {
    if (borrowCount >= 3) {
        cout << "借书失败，已达到最大借阅上限！" << endl;
        return false;
    }
    if (!book.getBorrowState()) {
        cout << "借书失败，图书已被借出！" << endl;
        return false;
    }
    book.setBorrowState(false);
    borrowCount++;
    cout << "借书成功！" << endl;
    return true;
}

bool Student::returnBook(Book& book) {
    if (borrowCount <= 0) {
        cout << "还书失败，没有借阅图书！" << endl;
        return false;
    }
    if (book.getBorrowState()) {
        cout << "还书失败，图书未借出！" << endl;
        return false;
    }
    book.setBorrowState(true);
    borrowCount--;
    cout << "还书成功！" << endl;
    return true;
}

void Student::showStudentInfo() const {
    cout << "学号：" << stuId << " 姓名：" << stuName << " 已借图书：" << borrowCount << "本" << endl;
}

