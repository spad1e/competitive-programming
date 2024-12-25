#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll a[MX], b[MX], dp[MX][64], l[MX], r[MX], stk[MX], t;

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) l[i] = r[i] = 0;
  rep(i, 1, n) rep(j, 64) dp[i][j] = LLONG_MAX;
  t = 0;
  rep(i, 1, n) {
    while (t && b[stk[t]] > b[i]) l[i] = stk[t--];
    if (t) r[stk[t]] = i; stk[++t] = i; 
  }
  int root = stk[1];
  function<void(int)> dfs = [&](int i) {
    if (i==0) return;
    int L = l[i], R = r[i];
    dfs(L); dfs(R);
    rep(s, 0, 63) rep(j, 0, s) {
      int k = s-j;
      ckmin(dp[i][s], max({dp[L][j], dp[R][k], a[i]}));
    }
    rep(s, 1, 63) ckmin(dp[i][s], (dp[i][s-1] + b[i] - 1) / b[i]);
  };
  dfs(root);
  rep(i, 0, 63) if (dp[root][i] == 1) return void(cout << i << nl);
} 

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}