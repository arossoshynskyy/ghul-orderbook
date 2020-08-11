from assertpy import assert_that

from ghulorderbook import OrderBook


def test_add_bid():
    order_book = OrderBook()

    order_book.add_bid("a", 123.0, 1000.0)

    assert_that(order_book.has_bid("a")).is_true()


def test_add_ask():
    order_book = OrderBook()

    order_book.add_ask("a", 123.0, 1000.0)

    assert_that(order_book.has_ask("a")).is_true()


def test_set_bid_amount():
    pass


def test_set_ask_amount():
    pass


def test_remove_bid():
    order_book = OrderBook()

    order_book.add_bid("a", 123.0, 1000.0)
    order_book.remove_bid("a")

    assert_that(order_book.has_bid("a")).is_false()


def test_remove_ask():
    order_book = OrderBook()

    order_book.add_ask("a", 123.0, 1000.0)
    order_book.remove_ask("a")

    assert_that(order_book.has_ask("a")).is_false()


def test_get_highest_bid():
    order_book = OrderBook()

    order_book.add_bid("a", 123.0, 1000.0)
    order_book.add_bid("b", 124.0, 1000.0)
    order_book.add_bid("c", 125.0, 1000.0)

    assert_that(order_book.get_highest_bid()).is_equal_to(125.0)


def test_get_lowest_ask():
    order_book = OrderBook()

    order_book.add_ask("a", 123.0, 1000.0)
    order_book.add_ask("b", 124.0, 1000.0)
    order_book.add_ask("c", 125.0, 1000.0)

    assert_that(order_book.get_lowest_ask()).is_equal_to(123.0)
