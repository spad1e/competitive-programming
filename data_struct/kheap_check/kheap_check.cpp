#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 3;
int a[MX];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    bool ok = 1;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
      if (a[i] > a[(i-1)/k]) ok = 0;
    }
    cout << (ok ? "true" : "false") << '\n';
  }
}