#pragma once
#include <string>
#include <iostream>
using namespace std;

class Resource
{
protected:
    string m_id;
    string m_name;
    bool m_state;

public:
    Resource(string id, string name, bool state = true)
        : m_id(id), m_name(name), m_state(state) {
    }

    virtual ~Resource() {}

    virtual void showInfo() const = 0;
    virtual bool borrowResource() = 0;
    virtual void returnResource() = 0;

    string getId() const { return m_id; }
    string getName() const { return m_name; }

    virtual bool getBorrowState() const { return m_state; }
    virtual void setBorrowState(bool st) { m_state = st; }
};