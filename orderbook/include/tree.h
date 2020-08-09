#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "limit.h"
#include "order.h"

using std::string;
using std::vector;
using std::unordered_map;


class Tree {
    Limit *root;
    unordered_map<double, Limit*> limits;
    unordered_map<string, Order*> orders;

    void insertLimit(Limit*);
    void removeLimit(Limit*);
    void rebalance(Limit*);
    void rightRotate(Limit*);
    void leftRotate(Limit*);
    Limit* rightMost(Limit*);
    Limit* leftMost(Limit*);
    void updateBalance(Limit*);

    public:
        void addOrder(string, double, double);
        void setOrderAmount(string, double);
        void addOrderAmount(string, double);
        void removeOrder(string);
        Limit* minLimit();
        Limit* maxLimit();
        vector<Limit*> inorder();
};


