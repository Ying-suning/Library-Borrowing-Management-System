#pragma once
#include "Book.h"
#include <vector>
class UniqueFeature
{
private:
    vector<Book> bookList;
public:
    void addBook(const Book& b);
    void execute(); 
};
