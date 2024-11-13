#include "sbtree.h"

sbtree *Sbtree()
{
    sbtree *t = new sbtree;
    
    t->parent = nullptr;
    t->left = nullptr;
    t->right = nullptr;

    return t;
}

void deleteTree(sbtree *t)
{
    if (t != nullptr) {
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
}

void insert(sbtree *t, int k)
{
    
}