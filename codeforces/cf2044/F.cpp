#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX];
vi factor[MX];

void solve() {
  int n, m, q; cin >> n >> m >> q;
  ll suma = 0, sumb = 0;
  set<int> sa, sb;
  rep(i, 1, n) cin >> a[i], suma += a[i], sa.insert(a[i]);
  rep(i, 1, m) cin >> b[i], sumb += b[i], sb.insert(b[i]);
  
  map<int, bool> mp; 
  while (q--) {
    int x; cin >> x;
    bool ok = 0;
    if (mp.count(x)) ok = mp[x];
    else for (auto f : factor[abs(x)]) if (sa.count(suma-f) && sb.count(sumb-x/f)) ok = 1; 
    cout << (ok ? "YES" : "NO") << nl;
    mp[x] = ok;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  rep(i, 1, MX-1) rep(j, i, MX-1, i) factor[j].pb(i), factor[j].pb(-i);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}