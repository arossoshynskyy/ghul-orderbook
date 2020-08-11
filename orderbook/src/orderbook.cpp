#include "orderbook.h"


void OrderBook::addBid(string id, float price, float amount) {
    bids.addOrder(id, price, amount);
};

void OrderBook::addAsk(string id, float price, float amount) {
    asks.addOrder(id, price, amount);
};

void OrderBook::setBidAmount(string id, float amount) {
    bids.setOrderAmount(id, amount);
};

void OrderBook::setAskAmount(string id, float amount) {
    asks.setOrderAmount(id, amount);
};

void OrderBook::removeBid(string id) {
    bids.removeOrder(id);
};

void OrderBook::removeAsk(string id) {
    asks.removeOrder(id);
};

bool OrderBook::hasBid(string id) {
    return bids.hasOrder(id);
}

bool OrderBook::hasAsk(string id) {
    return asks.hasOrder(id);
}

float OrderBook::getHighestBid() {
    Limit *limit = bids.getMaxLimit();

    if (limit) {
        return limit->getLevel();
    }
    return 0;
}

float OrderBook::getLowestAsk() {
    Limit *limit = asks.getMinLimit();

    if (limit) {
        return limit->getLevel();
    }
    return 0;
}
