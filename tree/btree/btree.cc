#include "btree.h"
#include <queue>
#include <iostream>
using namespace std;

btree *Btree()
{
    btree *t = new btree;
    t->parent = nullptr;
    t->left = nullptr;
    t->right = nullptr;

    return t;
}

btree *Btree(int k)
{
    btree *t = Btree();
    t->k = k;
    return t;
}

btree *Btree(int k, int v)
{
    btree *t = Btree(k);
    t->v = v;
    return t;
}

void deleteTree(btree *t)
{
    if (t != nullptr) {
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
}

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