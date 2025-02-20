#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

struct fenwick {
  vector<ll> t;
  int n;
  fenwick(int _n) {
    n = _n; t.assign(n+2, 0);
  }
  void update(int i, int val) {
    for (; i <= n; i += i&-i) t[i] = (t[i] + val) % MOD;
  }
  int query(int i) {
    int res = 0;
    for (; i > 0; i -= i&-i) res = (res + t[i]) % MOD;
    return res;
  }
};

ll p[MX];

void solve() {
  string s; cin >> s;
  int n = s.size(); s = " " + s;
  p[0] = 1; rep(i, 1, n) p[i] = (p[i-1] << 1) % MOD;

  fenwick fwL[2] = {n, n}, fwR[2] = {n, n};
  rep(i, 1, n) fwL[s[i]-'0'].update(i, p[i-1]);
  rep(i, 1, n) fwR[s[i]-'0'].update(i, p[n-i]);
  ll ans = p[n] - 1;
  rep(i, 1, n) ans = (ans + fwL[1 - (s[i]-'0')].query(i-1) * p[n-i] % MOD) % MOD;

  int q; cin >> q;
  while (q--) {
    int i; cin >> i;
    s[i] = (s[i]=='0'?'1':'0');
    int c = s[i]-'0';
    ans = (ans - fwL[c].query(i-1) * p[n-i]) % MOD;
    ans = (ans + fwL[1-c].query(i-1) * p[n-i]) % MOD;
    ans = (ans - (fwR[c].query(n) - fwR[c].query(i)) * p[i-1]) % MOD;
    ans = (ans + (fwR[1-c].query(n) - fwR[1-c].query(i)) * p[i-1]) % MOD;

    fwL[c].update(i, p[i-1]);
    fwL[1-c].update(i, -p[i-1]);
    fwR[c].update(i, p[n-i]);
    fwR[1-c].update(i, -p[n-i]);
    if (ans < 0) ans += MOD;
    cout << ans << " ";
  }
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}