#include "bstree.h"
#include <queue>
#include <iostream>
using namespace std;

bstree *Bstree()
{
    bstree *t = new bstree;
    t->parent = nullptr;
    t->left = nullptr;
    t->right = nullptr;

    return t;
}

bstree *Bstree(int k)
{
    bstree *t = Bstree();
    t->k = k;
    return t;
}

bstree *Bstree(int k, int v)
{
    bstree *t = bstree(k);
    t->v = v;
    return t;
}

void deleteTree(bstree *t)
{
    if (t != nullptr) {
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
}

bstree *lookup(bstree *t, int k)
{
    while (t != nullptr && t->k != k) {
        if (k < t->k)
            t = t->left;
        else
            t = t->right;
    }

    return t;
}

bstree *min(bstree *t)
{
    if (t == nullptr)
        return nullptr;
    
    while (t->left != nullptr)
        t = t->left;
    return t;
}

bstree *max(bstree *t)
{
    if (t == nullptr)
        return nullptr;
    
    while (t->right != nullptr)
        t = t->right;
    return t;
}

bstree *succ(bstree *t)
{
    if (t == nullptr)
        return nullptr;
    
    if (t->right != nullptr)
        return min(t->right);
    
    bstree *p = t->parent;
    while (p != nullptr && p->right == t) {
        t = p;
        p = p->parent;
    }

    return p;
}

void link(bstree *p, bstree *u, int k)
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

bstree *insert(bstree *t, int k)
{
    bstree *p = nullptr;
    bstree *u = t;

    while (u != nullptr && u->k != k) {
        p = u;
        u = k < u->k ? u->left : u->right;
    }

    if (u == nullptr) {
        bstree *n = bstree(k);
        link(p, n, k);
        if (p == nullptr)
            t = n;
    }

    return t;
}


bstree *insert(bstree *t, int k, int v)
{
    bstree *p = nullptr;
    bstree *u = t;

    while (u != nullptr && u->k != k) {
        p = u;
        u = k < u->k ? u->left : u->right;
    }

    if (u != nullptr && u->k == k) {
        u->v = v;
    } else {
        bstree *n = bstree(k, v);
        link(p, n, k);
        if (p == nullptr)
            t = n;
    }

    return t;
}


bstree *erase(bstree *t, int k)
{
    bstree *u = lookup(t, k); //find node to delete

    if (u != nullptr) { //if it was found...

        if (u->left == nullptr && u->right == nullptr) {
            link(u->parent, nullptr, k);
            delete u;
        } else if (u->left != nullptr && u->right != nullptr) {
            bstree *s = succ(u);
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

void dfs(bstree *t)
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

int count(bstree *t)
{
    if (nullptr == t)
        return 0;
    return 1 + count(t->left) + count(t->right);
}


void bfs(bstree *t)
{
    queue<bstree*> Q;

    if (t != nullptr)
        Q.push(t);

    while (!Q.empty()) {
        
        bstree *u = Q.front(); Q.pop();
        // then do something to u

        // then visit its children:
        if (u->left != nullptr)
            Q.push(u->left);
        if (u->right != nullptr)
            Q.push(u->right);
    }
}

void print_line(bstree *t)
{
    if (t != nullptr) {
        print_line(t->left);
        cout << t->k << " ";
        print_line(t->right);
    }
}

void print_tree(bstree *t, int space)
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

void print(bstree *t, bool tree_like)
{
    if (tree_like)
        print_tree(t, 0);
    else
        print_line(t);
    
    cout << endl;
}