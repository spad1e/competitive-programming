#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  if (n==nullptr) return 0;
  return process(n->left) + process(n->right) + 1;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  if (mSize == 0) return std::pair<KeyT, MappedT>();
  left.mRoot = mRoot->left; mRoot->left = nullptr;
  left.mSize = process(left.mRoot);
  right.mRoot = mRoot->right; mRoot->right = nullptr;
  right.mSize = process(right.mRoot);
  mSize = 1;
  return mRoot->data;
}

#endif

