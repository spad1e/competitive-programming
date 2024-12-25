#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node* n=mRoot;
  node* current = result.mRoot;
  int cnt = 0;
  while(n != NULL){
    ++cnt;
      // if (cnt == 1) break;
    if(val <= n->data.first){
      node* tmp = n->left;
      if(n != mRoot){
        if(n->left != NULL) {
          n->left->parent = n->parent;
          n->parent->right = n->left;
          n->left = NULL;
        }
        else {
          n->parent->right = NULL;
        }
        n->parent = NULL;
      }
      else{
        if(n->left != NULL) {
          n->left->parent = NULL;
        }
        mRoot = n->left;
        n->left = NULL;
      }
      if(result.mRoot == NULL) {
        result.mRoot = n;
        n->parent = NULL;
      }
      else{
        if (mRoot->left == NULL) current = mRoot;
        else node *ptr = find_node(n->data.first,result.mRoot,current);
        current->left = n;
        n->parent = current;
      }
      n = tmp;
    }
    else{
      n = n->right;
    }
  }
  return result;
}

#endif