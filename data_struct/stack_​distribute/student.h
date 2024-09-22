#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <vector>
#include<algorithm>

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  std::vector<std::vector<T>> ret;
  for (int i = mSize-1; i >= 0; --i) {
    if (ret.size() == 0 || ret.back().size() == mSize/k + (ret.size() <= mSize%k)) {
      ret.push_back(std::vector<T>());
    }
    ret.back().push_back(mData[i]);
  }
  return ret;
}
#endif
