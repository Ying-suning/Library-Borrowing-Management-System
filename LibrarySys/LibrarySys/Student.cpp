#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string id, string name) : stuId(id), stuName(name), borrowCount(0) {}

bool Student::borrowResource(Resource* res) {
    if (borrowCount >= 3) {
        cout << "借书失败，已达到最大借阅上限！" << endl;
        return false;
    }
    for (const string& id : borrowedIds) {
        if (id == res->getId()) {
            cout << "借书失败，你已借过该资源！" << endl;
            return false;
        }
    }

    if (res->borrowResource()) {
        borrowCount++;
        borrowedIds.push_back(res->getId());
        cout << "借阅成功！" << endl;
        return true;
    }
    else {
        cout << "借阅失败，资源已全部借出或不可用！" << endl;
        return false;
    }
}

bool Student::returnResource(Resource* res) {
    bool found = false;
    for (size_t i = 0; i < borrowedIds.size(); i++) {
        if (borrowedIds[i] == res->getId()) {
            borrowedIds.erase(borrowedIds.begin() + i);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "还书失败，你没有借该资源！" << endl;
        return false;
    }

    res->returnResource();
    borrowCount--;
    cout << "还书成功！" << endl;
    return true;
}

void Student::showStudentInfo() const {
    cout << "学号：" << stuId << " 姓名：" << stuName
        << " 已借资源：" << borrowCount << "个";
    if (!borrowedIds.empty()) {
        cout << " [";
        for (size_t i = 0; i < borrowedIds.size(); i++) {
            if (i) cout << ", ";
            cout << borrowedIds[i];
        }
        cout << "]";
    }
    cout << endl;
}