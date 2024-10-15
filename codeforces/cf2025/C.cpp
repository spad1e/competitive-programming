#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

void solve() {
  int n, k; cin >> n >> k;
  map<int, int> mp;
  rep(i, 1, n) {
    int a; cin >> a;
    mp[a]++;
  }
  queue<int> q;
  int ans = 0, cur = 0;
  for (auto [c, v] : mp) {
    while (!q.empty() && q.back()+1 != c) cur -= mp[q.front()], q.pop();
    while (!q.empty() && c - q.front() >= k) cur -= mp[q.front()], q.pop();
    cur += v;
    q.push(c);
    ckmax(ans, cur);
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}