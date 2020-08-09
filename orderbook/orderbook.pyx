from libcpp.string cimport string

from orderbook.orderbook cimport OrderBook


cdef class HFTOrderBook:
    cdef OrderBook* order_book
    
    def __cinit(self):
        self.order_book = new OrderBook()
    
    def add_bid(self, string id, double price, double amount):
        self.order_book.add_bid(id, price, amount)

    def add_ask(self, string id, double price, double amount):
        self.order_book.add_ask(id, price, amount)

    def set_bid_amount(self, string id, double amount):
        self.order_book.set_bid_amount(id, amount)

    def set_ask_amount(self, string id, double amount):
        self.order_book.set_ask_amount(id, amount)

    def remove_bid(self, string id):
        self.order_book.remove_bid(id)

    def remove_ask(self, string id):
        self.order_book.remove_ask(id)
