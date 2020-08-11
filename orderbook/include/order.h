#pragma once
#include <string>

using std::string;

struct Limit;

class Order {
    string id;
    float price;
    float amount;

    public:
        Order *next;
        Order *prev;
        Limit *parent;

        Order(string, float, float);
        string getId();
        float getPrice();
        float getAmount();
        void setAmount(float);
        void addAmount(float);
};