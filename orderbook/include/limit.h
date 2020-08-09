#pragma once
#include <string>

#include "order.h"

using std::string;

class Limit {
    double level;
    double amount;

    public:
        unsigned short int height;
        signed short int balance;

        Limit *parent;
        Limit *left;
        Limit *right;

        Order *head;
        Order *tail;

        explicit Limit(Order*);
        double getLevel();
        double getAmount();
        void addOrder(Order*);
        void removeOrder(Order*);
        bool hasOrders();
};
