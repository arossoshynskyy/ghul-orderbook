# cython: c_string_type=unicode, c_string_encoding=default

from libcpp.string cimport string

from orderbook.orderbook cimport OrderBook as CppOrderBook


cdef class OrderBook:
    cdef CppOrderBook order_book
    
    def __cinit__(self):
        self.order_book = CppOrderBook()

    def add_bid(self, string id_, float price, float amount):
        self.order_book.addBid(id_, price, amount)

    def add_ask(self, string id_, float price, float amount):
        self.order_book.addAsk(id_, price, amount)

    def set_bid_amount(self, string id_, float amount):
        self.order_book.setBidAmount(id_, amount)

    def set_ask_amount(self, string id_, float amount):
        self.order_book.setAskAmount(id_, amount)

    def remove_bid(self, string id_):
        self.order_book.removeBid(id_)

    def remove_ask(self, string id_):
        self.order_book.removeAsk(id_)

    def has_bid(self, string id_):
        return self.order_book.hasBid(id_)

    def has_ask(self, string id_):
        return self.order_book.hasAsk(id_)

    def get_highest_bid(self):
        return self.order_book.getHighestBid()

    def get_lowest_ask(self):
        return self.order_book.getLowestAsk()
