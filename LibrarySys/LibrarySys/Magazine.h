#pragma once
#include "Resource.h"

class Magazine : public Resource
{
private:
    string m_period;
public:
    Magazine(string name, string period, string id, bool state);

    void showInfo() const override;
    bool borrowResource() override;
    void returnResource() override;
};