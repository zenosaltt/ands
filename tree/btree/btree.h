#ifndef BTREE_H
#define BTREE_H

struct btree {

    btree *parent;
    btree *left;
    btree *right;

    int k;
    int v;

    btree();
    btree(int k);
    btree(int k, int v);
    ~btree();
    void insertLeft(btree *t);
    void insertRight(btree *t);
};

#endif