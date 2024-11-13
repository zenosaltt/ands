#ifndef SBTREE_H
#define SBTREE_H

struct sbtree {
    sbtree *parent;
    sbtree *left;
    sbtree *right;

    int key;
    int val;
};

sbtree *Sbtree();
void deleteTree(sbtree *t);

void insert(sbtree *t, int k);

#endif