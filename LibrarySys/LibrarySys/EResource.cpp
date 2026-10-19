#include "EResource.h"
#include <iostream>
using namespace std;

EResource::EResource(string name, string link, string id, bool state)
    : Resource(id, name), m_link(link), m_state(state)
{
}

void EResource::showInfo() const
{
    cout << "----电子资源信息----" << endl;
    cout << "资源名称：" << m_name << endl;
    cout << "访问链接：" << m_link << endl;
    cout << "资源编号：" << m_id << endl;
    if (m_state)
        cout << "状态：可访问" << endl;
    else
        cout << "状态：已占用" << endl;
}

bool EResource::getBorrowState() const
{
    return m_state;
}
void EResource::setBorrowState(bool st)
{
    m_state = st;
}
