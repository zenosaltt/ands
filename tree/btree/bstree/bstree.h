#ifndef BSTREE_H
#define BSTREE_H

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

//returns the node with key k
//(null if k is not there)
btree *lookup(btree *t, int k);

btree *min(btree *t);
btree *max(btree *t);

btree *succ(btree *t);
//btree *prev(btree *t);

btree *insert(btree *t, int k);
btree *insert(btree *t, int k, int v);
btree *erase(btree *t, int k);

void print(btree *t, bool tree_like);

#endif