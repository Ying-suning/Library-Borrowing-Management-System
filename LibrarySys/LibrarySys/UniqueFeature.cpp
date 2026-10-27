#include "UniqueFeature.h"
#include <iostream>

UniqueFeature::~UniqueFeature(){}

void UniqueFeature::addBook(Resource* b) { bookList.push_back(b); }

void UniqueFeature::execute()
{
    cout << "\n====特色功能（当前可借阅资源）====\n";
    for (Resource* r : bookList)
    {
        if (r->getBorrowState())
        {
            r->showInfo();
        }
    }
}