#pragma once
#include <string>
#include <vector>
#include "Resource.h"
using namespace std;

class Student {
private:
    string stuId;
    string stuName;
    int borrowCount;
    vector<string> borrowedIds;
public:
    Student() : borrowCount(0) {}
    Student(string id, string name);

    string getStuId() const { return stuId; }
    int getBorrowCount() const { return borrowCount; }

    bool borrowResource(Resource* res);
    bool returnResource(Resource* res);
    void showStudentInfo() const;
};