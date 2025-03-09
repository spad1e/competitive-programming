#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

ll sumsq(int l, int r) { return ((ll)r*(r+1)*(2*r+1)/6 - (ll)(l-1)*l*(2*l-1)/6) % MOD; }

void solve() {
  ll n, k; cin >> n >> k;
  ll sq = sqrt(n);
  int ans = n*((max(k-n, 0ll))%MOD)%MOD; // case p > n
  rep(i, 2, min(k, sq)) {
    vi num;
    int tmp = n;
    while (tmp > 0) num.pb(tmp % i), tmp /= i;
    reverse(all(num));
    ll cur = 1;
    for (auto x : num) ans = (ans + x*cur%MOD)%MOD, cur=cur*i%MOD;
  }
  if (k <= sq) return void(cout << ans << nl); 
  ll m = min(n, k);
  ans = (ans + n*(m*(m+1)/2 - sq*(sq+1)/2)%MOD) % MOD; 
  for (int l = sq+1, r; l <= m; l = r+1) {
    ll x = n/l; r = min(n/x, m); 
    ans = (ans + x*(r-l+1)%MOD) % MOD;
    ans = (ans - x*sumsq(l, r)%MOD) % MOD;  
  }
  if (ans < 0) ans += MOD;
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}