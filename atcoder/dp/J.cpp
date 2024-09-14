#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e2 + 3;

double dp[MX][MX][MX];
int a[MX], cnt[4];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
  rep(k, 0, n) rep(j, 0, n) rep(i, 0, n) {
    if (i==0&&j==0&&k==0) continue;
    double sum = n;
    if (i > 0) sum += i*dp[i-1][j][k];
    if (j > 0) sum += j*dp[i+1][j-1][k];
    if (k > 0) sum += k*dp[i][j+1][k-1];
    dp[i][j][k] = sum/(i+j+k);
  }
  cout << fixed << setprecision(9) << dp[cnt[1]][cnt[2]][cnt[3]] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}