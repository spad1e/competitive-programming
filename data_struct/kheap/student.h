#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>
#include <limits>

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
  if (idx == 0) return;
  int prt = (idx-1)/4;
  if (!mLess(mData[idx], mData[prt])) {
    std::swap(mData[idx], mData[prt]);
    fixUp(prt);
  }
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
  for (int i = 1; i <= 4; ++i) {
    int cur_idx = 4*idx+i;
    if (cur_idx >= mSize) break;
    bool ok = 1;
    for (int j = 1; j <= 4; ++j) {
      if (i==j || 4*idx+j >= mSize) continue;
      if (mLess(mData[cur_idx], mData[4*idx+j])) ok = 0; 
    }
    if (ok && cur_idx < mSize && mLess(mData[idx], mData[cur_idx])) {
      std::swap(mData[idx], mData[cur_idx]);
      fixDown(cur_idx);
      break;
    }
  }
}

#endif

