#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  auto itp = it.ptr->prev;
  CP::list<T> result;
  if (it==end()) return result;
  result.mSize = mSize - pos;
  end().ptr->prev->next = result.end().ptr;
  result.end().ptr->prev = end().ptr->prev;
  result.end().ptr->next = it.ptr;
  it.ptr->prev = result.end().ptr;

  mSize = pos;
  itp->next = end().ptr;
  end().ptr->prev = itp;
  return result;
}

#endif
