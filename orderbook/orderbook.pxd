from libcpp.string cimport string


cdef extern from "include/orderbook.h" nogil:
    cdef cppclass OrderBook:
        OrderBook() except +
        void addBid(string id, double price, double amount)
        void addAsk(string id, double price, double amount)
        void setBidAmount(string id, double amount)
        void setAskAmount(string id, double amount)
        void removeBid(string id)
        void removeAsk(string id)