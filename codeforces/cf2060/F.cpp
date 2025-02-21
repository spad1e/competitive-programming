#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;
const int L = 17;

ll dp[21][MX], cho[L];

ll binpow(ll a, ll b) {
  ll res = 1;
  for (; b; b>>=1, a=a*a%MOD) if (b&1) res=res*a%MOD;
  return res;
}

void solve() {
  int n, k; cin >> n >> k;
  dp[0][1] = 1;
  rep(l, 1, L) rep(i, 1, n) rep(j, 2*i, n, i)
   dp[l][j] = (dp[l][j] + dp[l-1][i]) % MOD;

  cho[0] = k+1;
  rep(i, 0, L-2) cho[i+1] = cho[i] * (k-i) % MOD * binpow(i+2, MOD-2) % MOD;
  rep(i, 1, n) {
    ll ans = 0, choose = k+1;
    rep(j, 0, L) ans = (ans + dp[j][i] * cho[j] % MOD) % MOD;
    cout << ans-(i==1) << " "; 
  }
  cout << nl;

  rep(j, 0, L) rep(i, 1, n) dp[j][i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}