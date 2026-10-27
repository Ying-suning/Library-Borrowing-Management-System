#include "Magazine.h"

Magazine::Magazine(string name, string period, string id, bool state)
    : Resource(id, name, state), m_period(period)
{
}

bool Magazine::borrowResource()
{
    if (m_state)
    {
        m_state = false;
        return true;
    }
    return false;
}

void Magazine::returnResource()
{
    m_state = true;
}

void Magazine::showInfo() const
{
    cout << "----杂志信息----" << endl;
    cout << "杂志名称：" << m_name << endl;
    cout << "刊期：" << m_period << endl;
    cout << "资源编号：" << m_id << endl;
    cout << "状态：" << (m_state ? "在馆" : "已借出") << endl;
}