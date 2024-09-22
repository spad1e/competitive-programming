#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  std::vector<T> tmp;
  int cur = 0;
  for (auto it = first; it != first+k; ++it) tmp.push_back(*it);
  for (auto it = first; it != last; ++it) {
    if (it + k < last) *it = *(it+k);
    else *it = tmp[cur++];
  }
}

#endif
