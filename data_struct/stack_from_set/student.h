#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  mCap = 1;
  mData = new T[mCap]();
  mSize = 0;

  for (auto it = last; it != first;) push(*(--it));
}

#endif
