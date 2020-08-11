from libcpp.string cimport string
from libcpp cimport bool


cdef extern from "include/orderbook.h" nogil:
    cdef cppclass OrderBook:
        OrderBook() except +
        void addBid(string, float, float)
        void addAsk(string, float, float)
        void setBidAmount(string, float)
        void setAskAmount(string, float)
        void removeBid(string)
        void removeAsk(string)
        bool hasBid(string)
        bool hasAsk(string) 
        float getHighestBid()
        float getLowestAsk()