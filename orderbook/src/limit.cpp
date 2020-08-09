#include "limit.h"
#include "order.h"


Limit::Limit(Order *order) {
    this->height = 0;
    this->balance = 0;
    this->level = order->getPrice();
    this->amount = order->getAmount();
};

double Limit::getLevel() {
    return this->level;
};

double Limit::getAmount() {
    return this->amount;
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

    this->amount += order->getAmount();
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

    this->amount -= order->getAmount();

    delete order;
};

bool Limit::hasOrders() {
    if (this->head) {
        return true;
    }

    return false;
}
