#include "limit.h"
#include "order.h"


Limit::Limit(Order *order) {
    level = order->getPrice();
    amount = 0;
    height = 0;
    balance = 0;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    head = nullptr;
    tail = nullptr;

    this->addOrder(order);
};

float Limit::getLevel() {
    return level;
};

float Limit::getAmount() {
    return amount;
};

void Limit::addOrder(Order *order) {
    order->parent = this;

    if (!this->head) {
        this->tail = order;
    } else {
        order->next = this->head;
        this->head->prev = order;
    }

    this->head = order;

    amount += order->getAmount();
};

void Limit::removeOrder(Order *order) {
    Order *next = order->next;
    Order *prev = order->prev;

    if (next) {
        next->prev = prev;
    } else {
        this->tail = prev;
    }

    if (prev) {
        prev->next = next;
    } else {
        this->head = next;
    }

    amount -= order->getAmount();
};

bool Limit::hasOrders() {
    if (this->head) {
        return true;
    }

    return false;
}
