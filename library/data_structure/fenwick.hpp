/*
Fenwick Tree / Binary Indexed Tree
Modified from : https://github.com/gean-dev/icpc-book/blob/main/content/data-structure/FenwickTree.hpp
verification : 
  https://cses.fi/problemset/task/1648/
  https://programming.in.th/tasks/1106 (test find method)
*/
#pragma once
#include "../template/header.hpp"
template<class T>
struct fenwick {
  int n;
  vector<T> t;
  fenwick (int n=0){init(n);}
  void init(int _n) {
    n=_n;
    t.assign(n+1, T{});
  }
  void update(int x, const T &v) {
    for(int i = x+1; i <= n; i+=i&-i) t[i] = t[i]+v;
  }
  void update(int l, int r, const T &v) {
    update(l, v); update(r+1, -v);
  }
  T query(int x) {
    T res{};
    for (int i = x+1; i > 0; i-=i&-i) res = res+t[i];
    return res;
  }
  T query(int l, int r) {
    return query(r) - query(l-1);
  }
  //find the first index that sums to >= k
  int find(const T &k) {
    int x = 0;
    T cur{};
    for (int i = 1<<(31-__builtin_clz(n)); i > 0; i>>=1)
      if (x+i <= n && cur+t[x+i] < k) x+=i, cur+=t[i];
    return x;
  }
};