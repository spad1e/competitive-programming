#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  int sz = last-first;
  int pos = position - begin();
  ensureCapacity(mSize + sz);
  for (int i = mSize-1; i >= pos; --i) {
    mData[i+sz] = mData[i];
  }
  for (auto it = first; it != last; ++it) {
    mData[pos++] = *it;
  }
  mSize += sz;
}

#endif
