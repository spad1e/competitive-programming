#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e5 + 3;

struct SegmentTree {
  vector<int> t, sf, pf, s;
  int n;
  SegmentTree(int _n) {
    n = _n;
    t.assign(n<<2, 0);
    sf.assign(n<<2, 0);
    pf.assign(n<<2, 0);
    s.assign(n<<2, 0);
  }
  void pull(int i) {
    s[i] = s[i<<1] + s[i<<1|1];
    pf[i] = max(pf[i<<1], pf[i<<1|1] + s[i<<1]);
    sf[i] = max(sf[i<<1|1], sf[i<<1] + s[i<<1|1]);
    t[i] = max({t[i<<1], t[i<<1|1], pf[i<<1|1] + sf[i<<1], 0});
  }
  void update(int l, int r, int x, int val, int idx) {
    if (l == r) return void(s[idx] = pf[idx] = sf[idx] = t[idx] = val);
    int mid = (l+r)>>1;
    if (x <= mid) update(l, mid, x, val, idx<<1);
    else update(mid+1, r, x, val, idx<<1|1);
    pull(idx);
  }
  void update(int x, int val) { update(1, n, x, val, 1); }
};

int a[MX], ans[MX];
vector<pii> v[MX];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) v[i].clear();
  rep(i, 1, n) v[a[i]].emplace_back(0, i);
  rep(i, 1, q) {
    int k, x; cin >> k >> x;
    v[a[k]].emplace_back(i, -k);
    v[a[k] = x].emplace_back(i, k);
  }
  SegmentTree t(n);
  rep(i, 1, n) t.update(i, -1);
  vector<pii> upd;
  rep(i, 1, n) {
    vector<int> revert;
    for (auto [idx, k] : v[i]) {
      upd.emplace_back(idx, t.t[1]);
      if (k < 0) t.update(-k, -1);
      else t.update(k, 1);
      upd.emplace_back(idx, -t.t[1]);
      revert.emplace_back(abs(k));
    }
    for (auto k : revert) t.update(k, -1);
  }
  sort(all(upd));
  multiset<int, greater<int>> ms;
  int j = 0;
  rep(i, 0, q) {
    while (j < upd.size() && upd[j].st == i) {
      auto [_, x] = upd[j++];
      if (x > 0) ms.erase(ms.find(x));
      else ms.insert(-x);
    }
    ans[i] = *ms.begin()/2;
  }
  rep(i, 1, q) cout << ans[i] << " "; cout << nl;
} 

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}