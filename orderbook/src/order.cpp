#include "order.h"


Order::Order(string id, double price, double amount) {
    this->id = id;
    this->price = price;
    this->amount = amount;
};

string Order::getId() {
    return this->id;
}

double Order::getPrice() {
    return this->price;
}

double Order::getAmount() {
    return this->amount;
}

void Order::setAmount(double amount) {
    this->amount = amount;
};

void Order::addAmount(double amount) {
    this->amount += amount;
};