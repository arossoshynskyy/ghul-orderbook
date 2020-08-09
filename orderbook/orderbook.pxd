from libcpp.string cimport string


cdef extern from "include/book.h" nogil:
    cdef cppclass OrderBook:
        OrderBook() except +
        void add_bid(string id, double price, double amount)
        void add_ask(string id, double price, double amount)
        void set_bid_amount(string id, double amount)
        void set_ask_amount(string id, double amount)
        void remove_bid(string id)
        void remove_ask(string id)