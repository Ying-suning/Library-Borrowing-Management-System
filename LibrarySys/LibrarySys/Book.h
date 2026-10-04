#pragma once
#include <string>
#include <iostream>
using namespace std;

class Book
{
private:
    string m_name;
    string m_author;
    string m_isbn;
    string m_id;
    string m_publisher;
    double m_price;
    bool m_state;
public:
    Book();
    Book(string na, string au, string isbn, string id, string pu, double pr, bool state);
    double getprice();
    void setprice(double pr);
    bool getstate() const;
    void setstate(bool st);
    void showBook() const;
    string getId();
};


