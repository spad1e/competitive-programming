#include <bits/stdc++.h>
using namespace std;

const int MX = 2e3 + 10;
int n, table[MX], state[MX];

int h(int b, int cnt) {
  return (b + cnt*cnt) % n;
}

int main() {
  int m; cin >> n >> m;
  for (int i = 0; i < n; ++i) table[i] = -1;
  while (m--) {
    int a, b; cin >> a >> b;
    if (a==1) {
      int cnt=0;
      while (state[h(b, cnt)]==1) cnt++;
      table[h(b, cnt)] = b;
      state[h(b, cnt)] = 1;
    }
    if (a==2) {
      int cnt=0;
      while (state[h(b, cnt)]!=0 && table[h(b, cnt)]!=b) cnt++;
      if (table[h(b, cnt)]==b) {
        table[h(b, cnt)] = -1;
        state[h(b, cnt)] = 2;
      }
    }
  }
  int mx1=0, mx2=0;
  for (int i = 0; i < n; ++i) {
    int cnt1=0, cnt2=0;
    while (state[h(i, cnt1)]==1) cnt1++; mx1 = max(mx1, cnt1);
    while (state[h(i, cnt2)]!=0) cnt2++; mx2 = max(mx2, cnt2);
  }
  cout << mx1+1 << " " << mx2+1 << '\n';
}