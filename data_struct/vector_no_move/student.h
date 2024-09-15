#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

std::vector<int> not_aux_but_actually_close;

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  auto it = std::upper_bound(not_aux_but_actually_close.begin(), not_aux_but_actually_close.end(), idx);
  int start, where = it - not_aux_but_actually_close.begin();
  if (it != aux.begin()) start = *(--it);
  else start = 0;
  return mData[where][idx-start];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  not_aux_but_actually_close.push_back(mCap);
}

#endif
