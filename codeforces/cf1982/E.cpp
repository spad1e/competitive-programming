#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 60 + 3;

ll dp[MX][MX][2];
ll dv = 500000004;

void solve() {
  ll n; int k; cin >> n >> k; n--;
  memset(dp, 0, sizeof(dp));
  function<int(int, int, int)> calc = [&](int i, int _k, int free) {
    if (dp[i][_k][free]) return dp[i][_k][free];
    if (_k == 0) return dp[i][_k][free] = 1;
    if (i == _k) {
      ll v = 1ll<<_k+1;
      if (!free) v = min(v, (n & (v-1))+2);
      return dp[i][_k][free] = v%MOD*((v-1)%MOD)%MOD*dv%MOD;
    }
    ll ret = 0;
    if (n>>i&1 || free==1) ret = (calc(i-1, _k-1, free) + calc(i-1, _k, 1)) % MOD;
    else ret = calc(i-1, _k, free);
    return dp[i][_k][free] = ret;
  };
  cout << calc(61, k, 0) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}