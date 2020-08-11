#include "order.h"


Order::Order(string id, float price, float amount) {
    this->id = id;
    this->price = price;
    this->amount = amount;
    next = nullptr;
    prev = nullptr;
    parent = nullptr;
};

string Order::getId() {
    return id;
}

float Order::getPrice() {
    return price;
}

float Order::getAmount() {
    return amount;
}

void Order::setAmount(float amount) {
    this->amount = amount;
};

void Order::addAmount(float amount) {
    this->amount += amount;
};