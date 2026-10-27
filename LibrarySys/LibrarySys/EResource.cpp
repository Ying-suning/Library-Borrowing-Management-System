#include "EResource.h"

EResource::EResource(string name, string link, string id, bool state)
    : Resource(id, name, state), m_link(link)
{
}

bool EResource::borrowResource()
{
    if (m_state)
    {
        m_state = false;
        return true;
    }
    return false;
}

void EResource::returnResource()
{
    m_state = true;
}

void EResource::showInfo() const
{
    cout << "----电子资源信息----" << endl;
    cout << "资源名称：" << m_name << endl;
    cout << "访问链接：" << m_link << endl;
    cout << "资源编号：" << m_id << endl;
    cout << "状态：" << (m_state ? "可访问" : "已失效/借出") << endl;
}