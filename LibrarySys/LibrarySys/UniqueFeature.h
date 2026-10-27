#pragma once
#include "Resource.h"
#include <vector>
using namespace std;

class UniqueFeature
{
private:
    vector<Resource*> bookList;
public:
    ~UniqueFeature();
    void addBook(Resource* b);
    void execute();
};