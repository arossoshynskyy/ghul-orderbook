#include "book.h"


Book::Book() {
    this->asks = new Tree();
    this->bids = new Tree();
}

void Book::addBid(string id, double price, double amount) {
    this->bids->addOrder(id, price, amount);
};

void Book::addAsk(string id, double price, double amount) {
    this->asks->addOrder(id, price, amount);
};

void Book::setBidAmount(string id, double amount) {
    this->bids->setOrderAmount(id, amount);
};

void Book::setAskAmount(string id, double amount) {
    this->asks->setOrderAmount(id, amount);
};

void Book::removeBid(string id) {
    this->bids->removeOrder(id);
};

void Book::removeAsk(string id) {
    this->asks->removeOrder(id);
};