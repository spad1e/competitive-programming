#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int MX = 2e5 + 3;

priority_queue<int, vector<int>, greater<int>> pq[10];

void solve() {
  string s; cin >> s;
  int n = s.size();
  int k; cin >> k;
  for (int i = 0; i < 10; ++i) while (!pq[i].empty()) pq[i].pop();
  for (int i = 0; i < n; ++i) pq[s[i]-'0'].push(i);
  int upto = -1;
  bool allow_zero = 0;
  string ans = "";
  int l = n - k;
  while (l--) {
    for (int j = 0; j < 10; ++j) {
      if (j == 0 && !allow_zero) continue;
      while (!pq[j].empty() && pq[j].top() <= upto) pq[j].pop();
      if (pq[j].empty()) continue;
      if (n - pq[j].top() < l+1) continue;
      ans += (char)('0' + j);
      upto = pq[j].top();
      break;
    }
    allow_zero = 1;
  }
  cout << ans << nl;
}
 
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}