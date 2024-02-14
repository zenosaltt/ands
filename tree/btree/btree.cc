#include "btree.h"
#include <queue>
using namespace std;

void dfs(btree *t)
{
    if (nullptr == t)
        return;
    // pre
    dfs(t->left);
    // in
    dfs(t->right);
    // post

    /*
    if (t != nullptr) {
        //pre
        dfs(t->left);
        //in
        dfs(t->right);
        //post
    }
    */
}

int count(btree *t)
{
    if (nullptr == t)
        return 0;
    return 1 + count(t->left) + count(t->right);
}


void bfs(btree *t)
{
    queue<btree*> Q;

    if (t != nullptr)
        Q.push(t);

    while (!Q.empty()) {
        
        btree *u = Q.front(); Q.pop();
        // then do something to u

        // then visit its children:
        if (u->left != nullptr)
            Q.push(u->left);
        if (u->right != nullptr)
            Q.push(u->right);
    }
}

void btree::insertLeft(btree *t)
{
    if (left != nullptr) {
        t->parent = this;
        this->left = t;
    }
}

void btree::insertRight(btree *t)
{
    if (right != nullptr) {
        t->parent = this;
        this->right = t;
    }
}

btree::btree()
{
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}