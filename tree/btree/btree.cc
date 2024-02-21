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

btree *lookup(btree *t, int k)
{
    while (t != nullptr && t->k != k) {
        if (k < t->k)
            t = t->left;
        else
            t = t->right;
    }

    return t;
}

btree *min(btree *t)
{
    if (t == nullptr)
        return nullptr;
    
    while (t->left != nullptr)
        t = t->left;
    return t;
}

btree *max(btree *t)
{
    if (t == nullptr)
        return nullptr;
    
    while (t->right != nullptr)
        t = t->right;
    return t;
}

btree *succ(btree *t)
{
    if (t == nullptr)
        return nullptr;
    
    if (t->right != nullptr)
        return min(t->right);
    
    btree *p = t->parent;
    while (p != nullptr && p->right == t) {
        t = p;
        p = p->parent;
    }

    return p;
}

void link(btree *p, btree *u, int k)
{
    if (u != nullptr)
        u->parent = p;
    if (p != nullptr) {
        if (k < p->k)
            p->left = u;
        else
            p->right = u;
    }
}

btree *insert(btree *t, int k)
{
    btree *p = nullptr;
    btree *u = t;

    while (u != nullptr && u->k != k) {
        p = u;
        u = k < u->k ? u->left : u->right;
    }

    if (u == nullptr) {
        btree *n = Btree(k);
        link(p, n, k);
        if (p == nullptr)
            t = n;
    }

    return t;
}


btree *insert(btree *t, int k, int v)
{
    btree *p = nullptr;
    btree *u = t;

    while (u != nullptr && u->k != k) {
        p = u;
        u = k < u->k ? u->left : u->right;
    }

    if (u != nullptr && u->k == k) {
        u->v = v;
    } else {
        btree *n = Btree(k, v);
        link(p, n, k);
        if (p == nullptr)
            t = n;
    }

    return t;
}


btree *erase(btree *t, int k)
{
    btree *u = lookup(t, k); //find node to delete

    if (u != nullptr) { //if it was found...

        if (u->left == nullptr && u->right == nullptr) {
            link(u->parent, nullptr, k);
            delete u;
        } else if (u->left != nullptr && u->right != nullptr) {
            btree *s = succ(u);
            link(s->parent, s->right, s->k);
            u->k = s->k;
            u->v = s->v;
            delete s;
        } else if (u->left != nullptr && u->right == nullptr) {

        } else {

        }
    }

    return t;
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

void print_line(btree *t)
{
    if (t != nullptr) {
        print_line(t->left);
        cout << t->k << " ";
        print_line(t->right);
    }
}

void print_tree(btree *t, int space)
{
    if (t != nullptr) {
        space += 5;
        print_tree(t->right, space);
        cout << endl;
        for (int i = 5; i < space; i++)
            cout << " ";
        cout << t->k << endl;
        print_tree(t->left, space);
    }
}

void print(btree *t, bool tree_like)
{
    if (tree_like)
        print_tree(t, 0);
    else
        print_line(t);
    
    cout << endl;
}