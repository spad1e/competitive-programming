#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int b[MX];

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> b[i];
  map<int, int> cnt;
  rep(i, 1, n) cnt[b[i]]++;
  vi v;
  for (auto [k, c] : cnt) v.pb(c);
  sort(all(v));
  int ans = v.size();
  for (auto c : v) if (k >= c) ans--, k -= c; 
  cout << max(1, ans) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}