#ifndef BSTREE_H
#define BSTREE_H

struct bstree {

    bstree *parent;
    bstree *left;
    bstree *right;

    int k; //key for binary search trees
    int v; //actual content of the node
};

bstree *Bstree();
bstree *Bstree(int k);
bstree *Bstree(int k, int v);

void deleteTree(bstree *t);

//returns the node with key k
//(null if k is not there)
bstree *lookup(bstree *t, int k);

bstree *min(bstree *t);
bstree *max(bstree *t);

bstree *succ(bstree *t);
//bstree *prev(bstree *t);

bstree *insert(bstree *t, int k);
bstree *insert(bstree *t, int k, int v);
bstree *erase(bstree *t, int k);

void print(bstree *t, bool tree_like);

#endif