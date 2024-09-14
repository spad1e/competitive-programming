#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

using matrix = vector<vector<ll>>;
int n; 

matrix mul(matrix a, matrix b) {
  matrix res(n, vll(n, 0));
  rep(i, n) rep(j, n) rep(k, n) res[i][j] = (res[i][j] + (ll)a[i][k]*b[k][j]%MOD) % MOD;
  return res;
}

matrix binpow(matrix a, ll k) {
  matrix res(n, vll(n, 0));
  rep(i, n) res[i][i] = 1;
  for (;k;k>>=1, a=mul(a, a)) if (k&1) res=mul(res, a); 
  return res;
}

void solve() {
  ll k; cin >> n >> k;
  matrix a(n, vector<ll>(n, 0));
  rep(i, n) rep(j, n) cin >> a[j][i];
  matrix res = binpow(a, k);
  ll ans = 0;
  rep(i, n) rep(j, n) ans = (ans + res[i][j]) % MOD;
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}