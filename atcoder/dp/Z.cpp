#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

struct CHT {
  struct Line {
    ll m, c;
    Line (ll _m, ll _c) { m = _m, c = _c; }
    ll eval(ll x) { return m*x + c; }
  };
  deque<Line> dq;
  
  bool check(Line base, Line cur, Line add) {
    return (cur.c - base.c)*(base.m - add.m) < (add.c - base.c)*(base.m - cur.m);
  }

  void insert(ll m, ll c) {
    Line l(m, c);
    while (dq.size() > 1 && !check(dq.end()[-2], dq.back(), l)) dq.pop_back();
    dq.push_back(l);
  }

  ll query(ll x) {
    while (dq.size() > 1 && dq[0].eval(x) < dq[1].eval(x)) dq.pop_front();
    return dq[0].eval(x);
  }
};

ll h[MX], dp[MX];

void solve() {
  ll n, c; cin >> n >> c;
  CHT cht;
  rep(i, 1, n) cin >> h[i];
  dp[1] = 0; cht.insert(2*h[1], -h[1]*h[1]);
  rep(i, 2, n) {
    dp[i] = h[i]*h[i] - cht.query(h[i]) + c;
    cht.insert(2*h[i], -h[i]*h[i] - dp[i]);
  }
  cout << dp[n] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}