from libcpp.string cimport string

from orderbook.orderbook cimport OrderBook as CppOrderBook


cdef class OrderBook:
    cdef CppOrderBook* order_book
    
    def __cinit(self):
        self.order_book = new CppOrderBook()
    
    def add_bid(self, string id, double price, double amount):
        self.order_book.addBid(id, price, amount)

    def add_ask(self, string id, double price, double amount):
        self.order_book.addAsk(id, price, amount)

    def set_bid_amount(self, string id, double amount):
        self.order_book.setBidAmount(id, amount)

    def set_ask_amount(self, string id, double amount):
        self.order_book.setAskAmount(id, amount)

    def remove_bid(self, string id):
        self.order_book.removeBid(id)

    def remove_ask(self, string id):
        self.order_book.removeAsk(id)

    def __dealloc__(self):
        del self.order_book
