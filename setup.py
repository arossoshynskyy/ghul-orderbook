from setuptools import Extension, setup
from Cython.Build import cythonize

sources = ["orderbook/orderbook.pyx", "orderbook/orderbook.cpp"]

ext_modules = cythonize(
    [Extension("orderbook", sources=sources, language="c++")], annotate=True
)

setup(
    author="Andriy Rossoshynskyy",
    description="A HFT order book written in C++ with a python wrapper",
    ext_modules=ext_modules,
    name="ghul-orderbook",
)
