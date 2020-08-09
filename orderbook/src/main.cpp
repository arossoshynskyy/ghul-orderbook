#include <iostream>
#include <vector>

#include "tree.h"


int main() {
    Tree *tree = new Tree();

    tree->addOrder("a", 8, 1);
    tree->addOrder("b", 2, 1);
    tree->addOrder("c", 4, 1);
    tree->addOrder("d", 5, 1);
    tree->addOrder("e", 3, 1);
    tree->addOrder("f", 1, 1);
    tree->addOrder("g", 7, 1);
    tree->addOrder("f100", 6, 1);
    tree->addOrder("g200", 9, 1);
    tree->addOrder("h300", 10, 1);
    tree->addOrder("i", 26, 1);
    tree->addOrder("j", 12, 1);
    tree->addOrder("k", 13, 1);
    tree->addOrder("l", 14, 1);
    tree->addOrder("m", 15, 1);
    tree->addOrder("n", 16, 1);
    tree->addOrder("o", 17, 1);
    tree->addOrder("p", 18, 1);
    tree->addOrder("q", 19, 1);
    tree->addOrder("r", 20, 1);
    tree->addOrder("s", 21, 1);
    tree->addOrder("t", 22, 1);
    tree->addOrder("u", 23, 1);
    tree->addOrder("v", 24, 1);
    tree->addOrder("w", 25, 1);
    tree->addOrder("z", 11, 1);
    tree->addOrder("g1", 27, 1);
    tree->addOrder("a2", 28, 1);
    tree->addOrder("b3", 29, 1);
    tree->addOrder("c4", 30, 1);
    tree->addOrder("d5", 31, 1);
    tree->addOrder("e6", 32, 1);
    tree->addOrder("f7", 33, 1);
    tree->addOrder("g8", 34, 1);
    tree->addOrder("99", 35, 1);
    tree->addOrder("g10", 36, 1);
    tree->addOrder("a11", 37, 1);
    tree->addOrder("b12", 38, 1);
    tree->addOrder("c13", 39, 1);
    tree->addOrder("d14", 40, 1);
    tree->addOrder("e15", 41, 1);
    tree->addOrder("f16", 42, 1);
    tree->addOrder("g18", 43, 1);
    tree->addOrder("f20", 44, 1);
    tree->addOrder("g21", 45, 1);
    tree->addOrder("a22", 46, 1);
    tree->addOrder("b23", 47, 1);
    tree->addOrder("c24", 48, 1);
    tree->addOrder("d25", 49, 1);
    tree->addOrder("e26", 50, 1);
    tree->addOrder("f27", 51, 1);
    tree->addOrder("g28", 52, 1);
    tree->addOrder("f29", 53, 1);
    tree->addOrder("g30", 54, 1);

    /*
    for(int i=0; i<1000; i++){
        tree->addOrder("g", i, 1);
    }*/

    vector<Limit*> limits = tree->inorder();

    for(auto it = limits.begin(); it != limits.end(); ++it) {
        std::cout << (*it)->getLevel() << std::endl;
    }

    //std::cout << orders << std::endl;

    return 0;
}
