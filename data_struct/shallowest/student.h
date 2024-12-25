#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  if (n == nullptr) return 1000000000;
  if (n->left == nullptr && n->right == nullptr) return 0;
  return std::min(shallowest_leaf(n->left), shallowest_leaf(n->right)) + 1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  if (mSize == 0) return -1;
  return shallowest_leaf(mRoot);
}


#endif
