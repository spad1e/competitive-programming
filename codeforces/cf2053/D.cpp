#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll binpow(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1, a=a*a%MOD) if (b&1) res = res*a%MOD;
  return res;
}

ll a[MX], b[MX], sa[MX], sb[MX];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) cin >> a[i], sa[i] = a[i]; a[n+1] = sa[n+1] = 1;
  rep(i, 1, n) cin >> b[i], sb[i] = b[i]; b[n+1] = sb[n+1] = 1;
  sort(sa+1, sa+n+1); sort(sb+1, sb+n+1);
  ll ans = 1;
  rep(i, 1, n) ans = ans * min(sa[i], sb[i]) % MOD;
  cout << ans << " ";
  rep(i, 1, q) {
    int o, x; cin >> o >> x;
    if (o == 1) {
      int idx = upper_bound(sa+1, sa+n+1, a[x]) - sa - 1;
      ans = ans * binpow(min(sa[idx], sb[idx]), MOD-2) % MOD;
      a[x]++, sa[idx]++;
      ans = ans * min(sa[idx], sb[idx]) % MOD;
    }
    if (o == 2) {
      int idx = upper_bound(sb+1, sb+n+1, b[x]) - sb - 1;
      ans = ans * binpow(min(sa[idx], sb[idx]), MOD-2) % MOD;
      b[x]++, sb[idx]++;
      ans = ans * min(sa[idx], sb[idx]) % MOD;
    }
    cout << ans << " ";
  } 
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}