#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  map<int, int> m;
  rep(i, 1, n) m[a[i]] = i;
  vector<pii> v;
  for (auto [x, y] : m) v.pb({y, x});
  sort(all(v));

  vector<int> ans;
  set<int> out;
  bool mxx = 1;
  pqg<pii> mn;
  pq<pii> mx;
  int c = v.size();
  int i = 0, l = 1, r = 1;
  while(c--) {
    while (out.count(v[i].nd)) i++;
    while (r <= v[i].st) {
      mx.push({a[r], -r});
      mn.push({a[r], r});
      r++;
    }
    if (mxx) {
      while (out.count(mx.top().st) || -mx.top().nd < l) mx.pop();
      auto [val, idx] = mx.top();
      ans.pb(val);
      out.ins(val);
      l = -idx;
    }
    else {
      while (out.count(mn.top().st) || mn.top().nd < l) mn.pop();
      auto [val, idx] = mn.top();
      ans.pb(val);
      out.ins(val);
      l = idx;
    }
    mxx = !mxx;
  }
  cout << sz(ans) << nl;
  for (auto i : ans) cout << i << " ";
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}