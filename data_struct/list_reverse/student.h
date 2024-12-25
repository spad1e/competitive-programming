#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  if (a==b) return a;
  auto ret = b.ptr->prev;
  for (auto it = a; it != b;) {
    auto nxt = it.ptr->next;
    std::swap(it.ptr->next, it.ptr->prev);
    it = nxt;
  }
  a.ptr->next->next = b.ptr->prev;
  b.ptr->prev->prev = a.ptr->next;
  a.ptr->next = b.ptr;
  b.ptr->prev = a.ptr;
  return ret;
}

#endif
