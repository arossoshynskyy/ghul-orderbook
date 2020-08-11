#include <string>
#include <vector>
#include <stack>
#include "tree.h"
#include "limit.h"

using std::string;
using std::vector;
using std::stack;


void Tree::insertLimit(Limit* limit) {
    this->limits[limit->getLevel()] = limit;

    if (!this->root) {
        this->root = limit;
        return;
    }

    Limit *root = this->root;

    while (true) {
        if (limit->getLevel() > root->getLevel()) {
            if (!root->right) {
                root->right = limit;
                limit->parent = root;
                this->rebalance(root);
                break;
            } else {
                root = root->right;
            }
        } else {
            if (!root->left) {
                root->left = limit;
                limit->parent = root;
                this->rebalance(root);
                break;
            } else {
                root = root->left;
            }
        }
    }

};

void Tree::removeLimit(Limit* limit) {
    this->limits.erase(limit->getLevel());

    Limit *parent = limit->parent;

    // Case no children
    if (!limit->left && !limit->right) {
        if (!parent) {
            this->root = nullptr;
        } else if (limit == parent->left) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        this->rebalance(parent);
        return;
    }

    // Case right child
    if (!limit->left) {
        limit->right->parent = parent;
        if (!parent) {
            this->root = limit->right;
        } else if (limit == parent->left) {
            parent->left = limit->right;
        } else {
            parent->right = limit->right;
        }
        this->rebalance(parent);
        return;
    }

    // Case left child
    if (!limit->right) {
        limit->left->parent = parent;
        if (!parent) {
            this->root = limit->left;
        } else if (limit == parent->left) {
            parent->left = limit->left;
        } else {
            parent->right = limit->left;
        }
        this->rebalance(parent);
        return;
    }

    // Case two children
    Limit *minRight = this->leftMost(limit->right);
    Limit *minRightParent = minRight->parent;

    if (minRight->right) {
        if (minRight == minRightParent->left) {
            minRightParent->left = minRight->right;
            minRightParent->left->parent = minRightParent;
        } else {
            minRightParent->right = minRight->right;
            minRightParent->right->parent = minRightParent;
        }
    } else {
        if (minRight == minRightParent->left) {
            minRightParent->left = nullptr;
        } else {
            minRightParent->right = nullptr;
        }
    }

    if (limit->left) {
        limit->left->parent = minRight;
    }
    minRight->left = limit->left;

    if (limit->right) {
        limit->right->parent = minRight;
    }
    minRight->right = limit->right;

    if (!parent) {
        this->root = minRight;
    } else if (limit == parent->left) {
        parent->left = minRight;
    } else {
        parent->right = minRight;
    }
    minRight->parent = parent;

    if (minRightParent == limit) {
        this->rebalance(minRight);
    } else {
        this->rebalance(minRightParent);
    }

    delete limit;
};

void Tree::rebalance(Limit* limit) {
    while (true) {
        if (!limit) {
            return;
        }

        Limit *left = limit->left;
        Limit *right = limit->right;

        this->updateBalance(limit);

        if (limit->balance < -1) { // right rotate
            if (left->balance > 0) { // right heavy
                this->leftRotate(limit->left);
            }
            this->rightRotate(limit);
        } else if (limit->balance > 1) { // left rotate 
            if (right->balance < 0) { // left heavy
                this->rightRotate(limit->right);
            }
            this->leftRotate(limit);
        } else {
            limit = limit->parent;
        }
    }
};

void Tree::rightRotate(Limit* limit) {
    Limit *root = limit->left;

    if (!limit->parent) {
        root->parent = nullptr;
        this->root = root;
    } else {
        root->parent = limit->parent;
        if (limit == limit->parent->left) {
            root->parent->left = root;
        } else {
            root->parent->right = root;
        }
    }

    limit->parent = root;
    limit->left = root->right;
    
    if (limit->left) {
        limit->left->parent = limit;
    }

    root->right = limit;

    this->updateBalance(limit);
    this->updateBalance(root);
};

void Tree::leftRotate(Limit* limit) {
    Limit *root = limit->right;

    if (!limit->parent) {
        root->parent = nullptr;
        this->root = root;
    } else {
        root->parent = limit->parent;
        if (limit == limit->parent->left) {
            root->parent->left = root;
        } else {
            root->parent->right = root;
        }
    }

    limit->parent = root;
    limit->right = root->left;

    if (limit->right) {
        limit->right->parent = limit;
    }

    root->left = limit;

    this->updateBalance(limit);
    this->updateBalance(root);
};

Limit* Tree::rightMost(Limit* limit) {
    while (limit->right) {
        limit = limit->right;
    }

    return limit;
};

Limit* Tree::leftMost(Limit* limit) {
    while (limit->left) {
        limit = limit->left;
    }

    return limit;
};

void Tree::updateBalance(Limit* limit) {
    unsigned short int height = 0;
    signed short int left = 0, right = 0;

    if (limit->left) {
        left = limit->left->height + 1;
    }

    if (limit->right) {
        right = limit->right->height + 1;
    }

    if (left >= right) {
        height = left;
    } else {
        height = right;
    }

    limit->balance = right - left;
    limit->height = height;
};

void Tree::addOrder(string id, float price, float amount) {
    Order *order = new Order(id, price, amount);
    Limit *limit;

    this->orders[id] = order;

    auto it = this->limits.find(price);
    if (it != limits.end()) {
        limit = it->second;
        limit->addOrder(order);
        return;
    }

    limit = new Limit(order);
    this->insertLimit(limit);
};

void Tree::setOrderAmount(string id, float amount) {
    Order *order = this->orders[id];

    order->setAmount(amount);
};

void Tree::addOrderAmount(string id, float amount) {
    Order *order = this->orders[id];

    order->addAmount(amount);
};

void Tree::removeOrder(string id) {
    auto it = this->orders.find(id);
    if (it != orders.end()) {
        Order *order = it->second;
        Limit *limit = order->parent;

        this->orders.erase(id);

        limit->removeOrder(order);
        delete order;

        if (!limit->hasOrders()) {
            this->removeLimit(limit);
        }
    }
};

bool Tree::hasOrder(string id) {
    auto it = orders.find(id);
    if (it != orders.end()) {
        return  true;
    }
    return false;
}

Limit* Tree::getMinLimit() {
    Limit *limit = this->root;

    if (limit) {
        while (limit->left) {
            limit = limit->left;
        }
    }

    return limit;
};

Limit* Tree::getMaxLimit() {
    Limit *limit = this->root;

    if (limit) {
        while (limit->right) {
            limit = limit->right;
        }
    }

    return limit;
};

vector<Limit*> Tree::inorder() {
    vector<Limit*> limits;
    stack<Limit*> stack;
    Limit* current = this->root;

    while (current || !stack.empty()) {
        while (current) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        limits.push_back(current);

        current = current->right;
    }

    return limits;
};

Tree::~Tree() {
    while (not this->orders.empty() )
    {
        auto const it = this->orders.begin();
        delete it->second;
        this->orders.erase(it);
    }

    while (not this->limits.empty() )
    {
        auto const it = this->limits.begin();
        delete it->second;
        this->limits.erase(it);
    }
}