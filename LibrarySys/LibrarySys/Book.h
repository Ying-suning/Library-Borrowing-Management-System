#pragma once
#include "Resource.h"

class Book : public Resource
{
private:
    string m_author;
    string m_isbn;
    string m_publisher;
    double m_price;
    int m_stock;

public:
    Book(string na, string au, string isbn, string id, string pu, double pr, int stock);
    Book();

    double getprice() const;
    void setprice(double pr);
    int getStock() const;
    void setStock(int s);
    bool isAvailable() const { return m_stock > 0; }

    void showInfo() const override;
    bool borrowResource() override;
    void returnResource() override;
};