#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int MX = 2e5 + 3;
const int MOD = 998244353;

ll dp[26][MX];
ll fac[MX], inv[MX];

ll power(ll a, int b) {
  ll res = 1;
  for (; b; b>>=1, a=a*a%MOD) if (b&1) res=res*a%MOD;
  return res;
}

void initfac() {
  fac[0] = 1;
  for (int i = 1; i < MX; ++i) fac[i] = (i*fac[i-1]) % MOD;
  for (int i = 0; i < MX; ++i) inv[i] = power(fac[i], MOD-2);
}

ll choose(ll n, ll k) {
  if (n < 0) return 0;
  if (k < 0) return 0;
  if (n < k) return 0;
  return fac[n]*inv[n-k]%MOD*inv[k]%MOD; 
}

int main() {
  initfac();
  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  map<int, int> cnt1, cnt2;
  for (auto c : s) cnt1[c-'A']++;
  for (auto c : t) cnt2[c-'A']++;
  for (int j = 0; j < MX; ++j) {
    int x = cnt1[0], y = cnt2[0];
    if (j > cnt2[1]) break;
    if (x-j > y) continue;
    dp[0][j] = choose(x, j)%MOD;
  }
  for (int j = 1; j < MX; ++j) dp[0][j] = (dp[0][j] + dp[0][j-1]) % MOD;
  for (int i = 1; i < 26; ++i) {
    for (int j = 0; j < MX; ++j) {
      int x = cnt1[i], y = cnt2[i];
      if (j > cnt2[i+1]) break;
      if (x-j > y) continue;
      dp[i][j] = dp[i-1][y-x+j]*choose(x, j)%MOD;
    }
    for (int j = 1; j < MX; ++j) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
  }
  ll ans = dp[25][0]*fac[n]%MOD;
  for (int i = 0; i < 26; ++i) ans = ans*inv[cnt1[i]]%MOD;
  cout << ans << '\n';
}