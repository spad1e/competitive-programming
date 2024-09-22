#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  T a;
  bool first = 1;
  for (auto i : pos) {
    if (i >= mSize) continue;
    T cur = mData[(mFront + i) % mCap];
    if (first) first = 0, a = cur;
    else if (comp(cur, a)) a = cur;
  }
  return a;
}

#endif
