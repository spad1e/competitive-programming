#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,int level,int depth) {
    if (n == nullptr) return;
    my_recur(n->left, level+1, depth); 
    if (n->left != nullptr && level >= depth) delete n->left, n->left = nullptr, mSize--; 
    my_recur(n->right, level+1, depth); 
    if (n->right != nullptr && level >= depth) delete n->right, n->right = nullptr, mSize--;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::trim(int depth) {
	my_recur(mRoot, 0, depth);
    if (depth == -1) {
        delete mRoot;
        mRoot = nullptr;
        mSize--;
    }
}

#endif
