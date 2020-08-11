#pragma once
#include <string>

#include "tree.h"

using std::string;


class OrderBook {
    Tree asks;
    Tree bids;

    public:
        void addBid(string, float, float);
        void addAsk(string, float, float);
        void setBidAmount(string, float);
        void setAskAmount(string, float);
        void removeBid(string);
        void removeAsk(string);
        bool hasBid(string);
        bool hasAsk(string);
        float getHighestBid();
        float getLowestAsk();
};
