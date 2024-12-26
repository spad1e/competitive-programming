#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n, k; cin >> n >> k;
  map<int, pii> cnt;
  rep(i, 1, n) cin >> a[i], cnt[a[i]%k].st++, cnt[a[i]%k].nd = i;
  for (auto [k, v] : cnt) if (v.st == 1) return void(cout << "YES" << nl << v.nd << nl);
  cout << "NO" << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}