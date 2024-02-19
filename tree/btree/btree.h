#ifndef BTREE_H
#define BTREE_H

struct btree {

    btree *parent;
    btree *left;
    btree *right;

    int k; //key for binary search trees
    int v; //actual content of the node
};

btree *Btree();
btree *Btree(int k);
btree *Btree(int k, int v);

void deleteTree(btree *t);

#endif