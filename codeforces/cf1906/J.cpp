#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int MX = 5e3 + 3;
const int MOD = 998244353;

ll dp[2][MX][2], p[MX], a[MX];

int main() {
  int n; cin >> n; 
  for (int i = 1; i <= n; ++i) cin >> a[i];
  p[0] = 1;
  for (int i = 1; i <= n; ++i) p[i] = (p[i-1]<<1) % MOD;
  dp[1][1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    int cur = i&1, prev = !cur;
    dp[cur][i][0] = 0;
    for (int j = i; j <= n; ++j) {
      if (i==1&&j==1) continue;
      dp[cur][j][1] = (dp[prev][j][0] + dp[prev][j][1]) % MOD;
      if (j == i) continue;
      dp[cur][j][0] = (dp[cur][j-1][1] + (a[j-1] < a[j] ? 1 : 0)*dp[cur][j-1][0]) % MOD;
      dp[cur][j][0] = (dp[cur][j][0] * p[j-i-1])%MOD;
    }
  }
  cout << (dp[n&1][n][0] + dp[n&1][n][1]) % MOD;
}