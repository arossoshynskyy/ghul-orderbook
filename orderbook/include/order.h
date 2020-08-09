#pragma once
#include <string>

using std::string;

struct Limit;

class Order {
    string id;
    double price;
    double amount;

    public:
        Order *next;
        Order *prev;
        Limit *parent;

        Order(string, double, double);
        string getId();
        double getPrice();
        double getAmount();
        void setAmount(double);
        void addAmount(double);
};