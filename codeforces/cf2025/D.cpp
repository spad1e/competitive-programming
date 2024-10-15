#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e3 + 3;

vector<int> stren[MX], intel[MX];
int dp[MX], tmp[MX];

void solve() {
  int n, m; cin >> n >> m;
  int cur = 0;
  rep(i, 1, n) {
    int a; cin >> a;
    if (a==0) cur++;
    if (a>0) intel[cur].pb(a);
    if (a<0) stren[cur].pb(-a);
  }
  rep(i, 0, m) sort(all(intel[i])), sort(all(stren[i]));
  rep(i, 1, m) {
    rep(j, 0, i) {
      int take_stren = (ub(all(intel[i]), j) - intel[i].begin()) + (ub(all(stren[i]), i-j) - stren[i].begin());
      int take_intel = (ub(all(intel[i]), j+1) - intel[i].begin()) + (ub(all(stren[i]), i-j-1) - stren[i].begin());
      ckmax(tmp[j], dp[j] + take_stren);
      ckmax(tmp[j+1], dp[j] + take_intel);
    } 
    rep(j, 0, i) dp[j] = tmp[j], tmp[j] = 0;
  }
  cout << *max_element(dp, dp+m+1) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}