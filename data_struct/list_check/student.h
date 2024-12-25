#ifndef __STUDENT_H__
#define __STUDENT_H__


template <typename T>
bool CP::list<T>::check() {
  auto remember = end().ptr, it = begin().ptr;
  for (int i = 0; i < mSize; ++i) {
    if (it == end().ptr) return 0;
    if (it == nullptr) return 0;
    if (it->prev != remember) return 0;
    remember = it;
    it=it->next;
  }
  if (it->prev != remember) return 0;
  if (it != end().ptr) return 0;

  return 1;
}


#endif
