#include "BookMall.h"

// BookMall.cpp
BookMall::BookMall() : m_resCount(0), m_stuCount(0)
{
    // 初始化指针数组，防止野指针
    for (int i = 0; i < MAX_RESOURCES; i++) {
        m_resources[i] = nullptr;
    }
}
// 【极其重要】清理指针数组
BookMall::~BookMall() {
    for (int i = 0; i < m_resCount; i++) {
        delete m_resources[i]; // 释放每个 new 出来的子类对象
        m_resources[i] = nullptr;
    }
}

// 存入指针
void BookMall::addResource(Resource* res) {
    if (m_resCount >= MAX_RESOURCES) {
        cout << "资源已满！" << endl;
        return;
    }
    m_resources[m_resCount++] = res;
}

// 多态展示
void BookMall::showAllResources() const {
    cout << "\n======== 图书馆全部资源 ========" << endl;
    for (int i = 0; i < m_resCount; i++) {
        // 这一句会自动调用具体对象的 showInfo()，因为 showInfo 是虚函数
        m_resources[i]->showInfo();
    }
}

// 根据 ID 查找
Resource* BookMall::findResourceById(const string& id) {
    for (int i = 0; i < m_resCount; i++) {
        if (m_resources[i]->getId() == id) {
            return m_resources[i];
        }
    }
    return nullptr;
}

// 借阅
bool BookMall::borrowResource(const string& stuId, const string& resId) {
    Student* pStu = findStudentById(stuId);
    Resource* pRes = findResourceById(resId);

    if (!pStu) { cout << "没有该学生" << endl; return false; }
    if (!pRes) { cout << "没有该资源" << endl; return false; }

    return pStu->borrowResource(pRes);
}
// 归还
bool BookMall::returnResource(const string& stuId, const string& resId) {
    Student* pStu = findStudentById(stuId);
    Resource* pRes = findResourceById(resId);

    if (!pStu) { cout << "归还失败：没有该学生" << endl; return false; }
    if (!pRes) { cout << "归还失败：没有该资源" << endl; return false; }

    return pStu->returnResource(pRes);
}