#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include <unordered_set>

template <typename T>
void CP::vector<T>::uniq() {
  std::unordered_set<T> s;
  for (int i = 0, j = 0; i < mSize; ++i) 
    if (!s.count(mData[i])) 
      s.insert(mData[i]), mData[j++] = mData[i]; 
  mCap = mSize = s.size();
}

#endif
