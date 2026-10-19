#pragma once
#include "Book.h"
//电子资源：公有继承Resource
class EResource : public Resource
{
private:
    string m_link;
    bool m_state;
public:
    EResource(string name, string link, string id, bool state);
    void showInfo() const override;
    bool getBorrowState() const;
    void setBorrowState(bool st);
};