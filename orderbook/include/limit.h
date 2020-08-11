#pragma once
#include <string>

#include "order.h"

using std::string;

class Limit {
    float level;
    float amount;

    public:
        unsigned short int height;
        signed short int balance;

        Limit *parent;
        Limit *left;
        Limit *right;

        Order *head;
        Order *tail;

        explicit Limit(Order*);
        float getLevel();
        float getAmount();
        void addOrder(Order*);
        void removeOrder(Order*);
        bool hasOrders();
};
