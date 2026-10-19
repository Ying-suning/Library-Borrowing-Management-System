#include "Magazine.h"
#include <iostream>
using namespace std;

Magazine::Magazine(string name, string period, string id, bool state)
    : Resource(id, name), m_period(period), m_state(state)
{
}

void Magazine::showInfo() const
{
    cout << "----杂志信息----" << endl;
    cout << "杂志名称：" << m_name << endl;
    cout << "刊期：" << m_period << endl;
    cout << "资源编号：" << m_id << endl;
    if (m_state)
        cout << "状态：在馆" << endl;
    else
        cout << "状态：已借出" << endl;
}

bool Magazine::getBorrowState() const
{
    return m_state;
}
void Magazine::setBorrowState(bool st)
{
    m_state = st;
}
