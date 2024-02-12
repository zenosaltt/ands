#ifndef BTREE_H
#define BTREE_H

struct btree {

    btree *parent;
    btree *left;
    btree *right;

    int k;
};

#endif