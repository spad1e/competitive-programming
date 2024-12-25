#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  bool ok = 1;
  for (int i = 0; i < mSize; ++i) {
    if (2*i+1 < mSize && mLess(mData[i], mData[2*i+1])) ok = 0;
    if (2*i+2 < mSize && mLess(mData[i], mData[2*i+2])) ok = 0;
  }
  return ok;
}

#endif