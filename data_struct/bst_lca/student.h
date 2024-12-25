
#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "map_bst.h"


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::recursive(node* n,CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{

}


template <typename KeyT,
          typename MappedT,
          typename CompareT>
typename CP::map_bst<KeyT,MappedT,CompareT>::iterator CP::map_bst<KeyT,MappedT,CompareT>::lca(CP::map_bst<KeyT,MappedT,CompareT>::iterator p, CP::map_bst<KeyT,MappedT,CompareT>::iterator q) const
{
    auto it1 = mRoot, it2 = mRoot;
    if (p==q) return p;
    while (it1 == it2) {
        if (it1->data==*p) return it1;
        if (it2->data==*q) return it2;
        auto nxtit1 = (it1->data > *p ? it1->left : it1->right);
        auto nxtit2 = (it2->data > *q ? it2->left : it2->right);
        if (nxtit1 != nxtit2) return it1;
        it1 = nxtit1;
        it2 = nxtit2;
    }
}

#endif
