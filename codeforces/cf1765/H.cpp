#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;

const char nl = '\n';
const int MX = 2e3 + 3;

int p[MX], deg[MX], tdeg[MX];
vector<int> adj[MX];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 1; i <= m; ++i) {
    int a, b; cin >> a >> b;
    adj[b].push_back(a); tdeg[a]++;
  }
  for (int c = 1; c <= n; ++c) {
    for (int i = 1; i <= n; ++i) deg[i] = tdeg[i];
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; ++i) if (i != c && deg[i] == 0) pq.push({p[i], i});
    for (int i = n; i >= 1; --i) {
      int a;
      if (pq.empty() || pq.top().st < i) { a = c; cout << i << " "; }
      else { a = pq.top().nd; pq.pop(); }
      for (auto b : adj[a]) if (--deg[b] == 0 && b != c) pq.push({p[b], b});
    }
  }
  cout << nl;
}
 
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}