#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n, k; cin >> n >> k;
  map<int, int> mp;
  rep(i, 1, k) {
    int b, c; cin >> b >> c;
    mp[b] += c;
  }
  vi a;
  for (auto [k, v] : mp) a.pb(v);
  sort(all(a), greater<int>());
  cout << accumulate(a.begin(), a.begin()+min((int)a.size(), n), 0) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}