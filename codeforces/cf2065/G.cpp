#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;
const int SQMX = 500;

int mark[SQMX + 5];
vi prime;

void solve() {
  int n; cin >> n;
  map<int, int> mp1, mp2; 
  ll ans = 0, sum = 0;
  rep(i, 1, n) {
    int x; cin >> x;
    int xx = x; mp1[x]++;
    vi cp;
    for (auto p : prime) while (x % p == 0) cp.pb(p), x /= p;
    if (x != 1) cp.pb(x);
    if (cp.size() > 2) continue;
    if (cp.size() > 1) {
      mp2[cp[0]]++;
      if (cp[0] != cp[1]) mp2[cp[1]]++;
    }
    else sum++;

    if (cp.size() > 1) ans += mp1[xx] + mp1[cp[0]] + (cp[0] != cp[1] ? mp1[cp[1]] : 0);
    else ans += mp2[cp[0]] + (sum - mp1[cp[0]]);
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);

  rep(i, 2, SQMX) {
    if (mark[i]) continue;
    prime.pb(i);
    rep(j, i, SQMX, i) mark[j] = 1; 
  }

  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}