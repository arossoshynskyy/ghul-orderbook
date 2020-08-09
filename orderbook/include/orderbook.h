#pragma once
#include <string>

#include "tree.h"

using std::string;


class OrderBook {
    Tree *asks;
    Tree *bids;

    public:
        explicit OrderBook();
        void addBid(string, double, double);
        void addAsk(string, double, double);
        void setBidAmount(string, double);
        void setAskAmount(string, double);
        void removeBid(string);
        void removeAsk(string);
};
