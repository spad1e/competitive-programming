#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int MX = 2e3 + 3;
vector<int> p[MX];
int dp[MX][MX], from[MX][MX]; // 0 = not choose i, 1 = choose i

int main() {
  int n; cin >> n;  
  int mx = 0, cnt = 0;
  for (int i = 1; i <= 2*n; ++i) {
    int x; cin >> x;
    if (x > mx) { mx = x; cnt++; }
    p[cnt].push_back(x);
  }
  dp[0][0] = 1;
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = dp[i-1][j];
      if (j - p[i].size() >= 0 && dp[i-1][j-p[i].size()]) dp[i][j] = from[i][j] = 1;
      else dp[i][j] = dp[i-1][j];
    }
  }
  if (!dp[cnt][n]) { cout << -1 << '\n'; return 0; }
  for (int i = 1; i <= cnt; ++i) reverse(p[i].begin(), p[i].end());
  vector<int> v[2];
  int cur = n;
  for (int i = cnt; i > 0; --i) {
    for (auto x : p[i]) v[from[i][cur]].push_back(x);
    if (from[i][cur]) cur -= p[i].size();
  }
  reverse(v[0].begin(), v[0].end());
  reverse(v[1].begin(), v[1].end());
  for (auto x : v[0]) cout << x << " "; cout << '\n';
  for (auto x : v[1]) cout << x << " "; cout << '\n';
}