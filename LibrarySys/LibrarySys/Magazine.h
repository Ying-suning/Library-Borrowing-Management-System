#pragma once
#include "Book.h"
class Magazine : public Resource
{
private:
    string m_period;   
    bool m_state; 
public:
    Magazine(string name, string period, string id, bool state);
    void showInfo() const override;
    bool getBorrowState() const;
    void setBorrowState(bool st);
};

