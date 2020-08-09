#include "orderbook.h"


OrderBook::OrderBook() {
    this->asks = new Tree();
    this->bids = new Tree();
}

void OrderBook::addBid(string id, double price, double amount) {
    this->bids->addOrder(id, price, amount);
};

void OrderBook::addAsk(string id, double price, double amount) {
    this->asks->addOrder(id, price, amount);
};

void OrderBook::setBidAmount(string id, double amount) {
    this->bids->setOrderAmount(id, amount);
};

void OrderBook::setAskAmount(string id, double amount) {
    this->asks->setOrderAmount(id, amount);
};

void OrderBook::removeBid(string id) {
    this->bids->removeOrder(id);
};

void OrderBook::removeAsk(string id) {
    this->asks->removeOrder(id);
};