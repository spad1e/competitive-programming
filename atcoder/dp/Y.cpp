#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll fac[MX], inv[MX], dp[MX];
pii p[MX];

ll binpow(ll a, ll b) {
  ll ret = 1;
  for (;b;b>>=1,a=a*a%MOD) if (b&1) ret=ret*a%MOD;
  return ret;
}

void initfac() {
  fac[0] = 1;
  rep(i, 1, MX-1) fac[i] = (fac[i-1] * i) % MOD;
  rep(i, 0, MX) inv[i] = binpow(fac[i], MOD-2); 
}

ll choose(ll n, ll r) {
  if (n < 0 || r < 0 || n < r) return 0;
  return fac[n]*inv[r]%MOD*inv[n-r]%MOD;
}

void solve() {
  int h, w, n; cin >> h >> w >> n;
  rep(i, 1, n) cin >> p[i].st >> p[i].nd;
  p[++n] = {h, w};
  sort(p+1, p+n+1);
  rep(i, 1, n) {
    dp[i] = choose(p[i].st + p[i].nd - 2, p[i].st - 1);
    rep(j, 1, i-1) if (p[j].nd <= p[i].nd) dp[i] = (dp[i] - dp[j]*choose(p[i].st+p[i].nd - p[j].st-p[j].nd, p[i].st-p[j].st)%MOD) % MOD;
    if (dp[i] < 0) dp[i] += MOD;
  }
  cout << dp[n] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  initfac();
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}