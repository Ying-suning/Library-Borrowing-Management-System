#pragma once
#include <string>
#include <iostream>
using namespace std;

class Resource
{
protected:
    string m_id;
    string m_name;
public:
    Resource(string id, string name) : m_id(id), m_name(name) {}
    virtual void showInfo() const = 0;
    string getId() const { return m_id; }
};

class Book : public Resource
{
private:
    string m_author;
    string m_isbn;
    string m_publisher;
    double m_price;
    bool m_state;
public:
    Book(string na, string au, string isbn, string id, string pu, double pr, bool state);
    Book();
    double getprice() const;
    void setprice(double pr);
    bool getBorrowState() const;
    void setBorrowState(bool st);
    void showInfo() const override;
};
