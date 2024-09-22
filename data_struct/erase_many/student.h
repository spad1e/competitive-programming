#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  for (int i = 0, j = 0, k = 0; i < mSize; ++i) {
    if (j < pos.size() && i == pos[j]) j++;
    else mData[k++] = mData[i];
  }
  mSize = mCap = mSize - pos.size();
}

#endif
