#ifndef BOOKMALL_H
#define BOOKMALL_H

#include "Student.h"
#include "Resource.h"
#include <vector>
#include <iostream>
using namespace std;

const int MAX_STUS = 10;
const int MAX_RESOURCES = 20; // 假设最多20个资源

class BookMall {
private:
    Resource* m_resources[MAX_RESOURCES];
    int m_resCount;

    // 学生数组
    Student m_stus[MAX_STUS];
    int m_stuCount;

public:
    BookMall();

    // 析构函数：必须释放指针指向的内存，防止内存泄漏
    ~BookMall();

    // 添加资源（参数变成基类指针，实现依赖倒置）
    void addResource(Resource* res);

    // 展示所有资源（多态调用）
    void showAllResources() const;

    // 查找资源（返回基类指针）
    Resource* findResourceById(const string& id);

    void addStudent(const Student& s) {
        if (m_stuCount >= MAX_STUS) {
            cout << "学生名额已满！" << endl;
            return;
        }
        m_stus[m_stuCount++] = s;
    }
    void showAllStudents() const {
        cout << "\n======== 所有学生 ========" << endl;
        for (int i = 0; i < m_stuCount; i++) {
            cout << "--- 第" << i + 1 << "个学生 ---" << endl;
            m_stus[i].showStudentInfo();
        }
    }
    Student* findStudentById(const string& id) {
        for (int i = 0; i < m_stuCount; i++) {
            if (m_stus[i].getStuId() == id) return &m_stus[i];
        }
        return nullptr;
    }


    // --- 借还逻辑 ---
    bool borrowResource(const string& stuId, const string& resId);
    bool returnResource(const string& stuId, const string& resId);
};

#endif