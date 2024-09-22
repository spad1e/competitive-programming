#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  int sz = data.size();
  std::sort(data.begin(), data.end());
  ensureCapacity(mSize + sz);
  int idx = mSize;
  for (int i = mSize + sz -1; i >= 0; --i) {
    if (data[data.size()-1].first == idx) {
      mData[i] = data[data.size()-1].second;
      data.pop_back();
    }
    else mData[i] = mData[--idx];
  }
  mSize += sz;
}

#endif
