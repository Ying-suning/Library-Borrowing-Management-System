#include "UniqueFeature.h"
#include <iostream>
using namespace std;

void UniqueFeature::addBook(const Book& b)
{
    bookList.push_back(b);
}

void UniqueFeature::execute()
{
    cout << "\n====特色功能====\n";
    for (const auto& book : bookList)
    {
        if (book.getBorrowState())
        {
            book.showInfo();
        }
    }
}

