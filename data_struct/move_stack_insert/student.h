#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  CP::stack<T> t1, t2;
  while (m-- && s2.size()) {
    t1.push(s2.top());
    s2.pop();
  }
  while (k-- && size()) {
    t2.push(top());
    pop();
  }
  while (t1.size()) push(t1.top()), t1.pop();
  while (t2.size()) push(t2.top()), t2.pop();
}
#endif
