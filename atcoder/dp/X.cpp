#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

ll w[MX], s[MX], v[MX], p[MX];
ll dp[20003];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> w[i] >> s[i] >> v[i], p[i] = i;
  sort(p+1, p+n+1, [&](const int &a, const int &b) {
    return s[a] + w[a] < s[b] + w[b];
  });
  rep(i, 1, n) {
    int x = p[i];
    repd(j, 0, s[x]) {
      dp[j+w[x]] = max(dp[j+w[x]], dp[j] + v[x]);
    }
  }
  cout << *max_element(dp, dp+20001) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}