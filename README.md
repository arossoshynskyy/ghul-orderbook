# ghul-orderbook

A HFT order book written in C++ with a python wrapper.


## Install
```
pip install ghul-orderbook
```

## Usage

```python
from ghulorderbook import OrderBook

order_book = OrderBook()
```

## Testing
To run unittests and benchmarks use tox:

```
pipenv install --dev
pipenv run tox
```
