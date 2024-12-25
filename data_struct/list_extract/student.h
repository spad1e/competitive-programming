#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  for (auto it = a; it != b; ++it) {
    if (*it == value) {
      node *n = new node(value, output.end().ptr, output.begin().ptr);
      output.begin().ptr->prev = n;
      output.end().ptr->next = n;
      output.mSize++;
      
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      mSize--;
    }
  }
}

#endif
