#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  std::vector<T> r;
  for (int i = (1<<k)-1; i < std::min((1<<k+1)-1, (int)mSize); ++i) r.push_back(mData[i]);
  std::sort(r.begin(), r.end(), mLess);
  std::reverse(r.begin(), r.end());
  return r;
}

#endif

