#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int MX = 5e3 + 3;

struct chem {
  int x, w, c;
  void read() { cin >> x >> w >> c; }
  bool operator<(const chem &ch) const {
    return x < ch.x;
  }
} chem[MX];
double dp[MX];

void solve() {
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; ++i) chem[i].read();
  sort(chem+1, chem+n+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      double w = 1.0*(chem[i].x - chem[j].x)/100;
      double h = min(chem[i].c, chem[j].c);
      double H = max(chem[i].c, chem[j].c);

      dp[i] = max(dp[i], dp[j] + (w*h + w*(H-h)/2)*k);
    }
    dp[i] -= chem[i].w;
  }
  double ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
  cout << fixed << setprecision(10) << ans << nl;
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}