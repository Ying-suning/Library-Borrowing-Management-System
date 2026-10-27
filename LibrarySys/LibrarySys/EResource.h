#pragma once
#include "Resource.h"

class EResource : public Resource
{
private:
    string m_link;
public:
    EResource(string name, string link, string id, bool state);

    void showInfo() const override;
    bool borrowResource() override;
    void returnResource() override;
};