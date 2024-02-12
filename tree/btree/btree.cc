#include "btree.h"

void dfs(btree *t)
{
    if (t != nullptr) {
        //pre
        dfs(t->left);
        //in
        dfs(t->right);
        //post
    }
}

int count(btree *t)
{
    if (nullptr == t)
        return 0;
    return 1 + count(t->left) + count(t->right);
}


void bfs(btree *t)
{

}