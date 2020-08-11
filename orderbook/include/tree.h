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
    unordered_map<float, Limit*> limits;
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
        void addOrder(string, float, float);
        void setOrderAmount(string, float);
        void addOrderAmount(string, float);
        void removeOrder(string);
        bool hasOrder(string);
        Limit* getMinLimit();
        Limit* getMaxLimit();
        vector<Limit*> inorder();
        ~Tree();
};


