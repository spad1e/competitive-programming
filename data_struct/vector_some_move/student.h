#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

const int MAGIC = 1532;

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  int i = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
  if (i > 0) index -= aux[i-1];
  if (i == mData.size()) mData.push_back(value);
  else mData[i].insert(mData[i].begin() + index, value.begin(), value.end());
  if (mData[i].size() > MAGIC) {
    mData.insert(mData.begin()+i+1, std::vector<T>(mData[i].begin()+MAGIC, mData[i].end()));
    mData[i].resize(MAGIC);
  }
  aux.resize(mData.size());
  for (; i < mData.size(); ++i) aux[i] = (i>0 ? aux[i-1] : 0) + mData[i].size();
  mSize=mCap=aux.back();
}

#endif