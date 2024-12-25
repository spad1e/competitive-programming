#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  CP::map_bst<KeyT,MappedT,CompareT> result;

  node *cur = mRoot, *cur_res = nullptr;
  while (cur != nullptr) {
    if (cur->data.first >= val) {
      auto nxt = cur->left;
      
      if (cur == mRoot) {
        mRoot = cur->left;
        cur->parent = nullptr;
      }
      else {
        cur->parent->right = cur->left;
        if (cur->left != nullptr) cur->left->parent = cur->parent;
      }
      cur->left = nullptr;

      if (cur_res == nullptr) result.mRoot = cur;
      else cur_res->left = cur;
      if (cur->parent != nullptr) cur->parent = cur_res;
      cur_res = cur;

      cur = nxt;
    }
    else cur = cur->right;
  }

  return result;
}

#endif
