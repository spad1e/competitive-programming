#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

ll a[MX];
int idx[MX], x[MX], ans[MX], prt[MX], sz[MX];
bool mark[MX];
map<int, int> mp[MX];

int f(int i) {
  return (i == prt[i] ? i : prt[i] = f(prt[i]));
}

void join(int i, int j) {
  int fi = f(i), fj = f(j);
  if (fi == fj) return;
  if (mp[fi].size() > mp[fj].size()) swap(mp[fi], mp[fj]);
  for (auto [k, v] : mp[fi]) mp[fj][k] += v;
  sz[fj] += sz[fi];
  prt[fi] = fj;
}

struct maxset {
  multiset<int> s;
  int mx;
  maxset(int m):mx(m) {}
  void insert(int i) {
    int fi = f(i);
    if (mp[fi].size() == mx) s.insert(sz[fi]);
  }
  void erase(int i) {
    int fi = f(i);
    auto it = s.find(sz[fi]);
    if (mp[fi].size() == mx && it != s.end()) s.erase(it);
  }
  int get_max() {
    return (s.empty() ? -1 : *s.rbegin());
  }
};

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, q) cin >> idx[i] >> x[i];
  rep(i, 1, q) ans[i] = 0;

  for (int mx = 1; mx <= n; mx<<=1) {
    rep(i, 1, n) prt[i] = i, mp[i].clear(), sz[i] = 1, mark[i] = 0;
    rep(i, 1, q) a[idx[i]] += x[i];
    rep(i, 1, n) mark[i] = (a[i] < mx), mp[i][a[i]]++;
    maxset s(mx);
    rep(i, 1, n) if (mark[i]) s.insert(i);
    rep(i, 2, n) {
      if (mark[i-1] && mark[i]) {
        s.erase(i-1), s.erase(i);
        join(i-1, i);
        s.insert(i);
      }
    }

    repd(i, 1, q) {
      ckmax(ans[i], s.get_max());

      int id = idx[i], v = x[i], fid = f(id);
      if (mark[id]) s.erase(id);
      if (--mp[fid][a[id]] == 0) mp[fid].erase(a[id]);
      mp[fid][a[id] -= v]++;
      if (!mark[id] && a[id] < mx) {
        mark[id] = 1;
        if (id > 1 && mark[id-1]) s.erase(id-1), join(id-1, id);
        if (id < n && mark[id+1]) s.erase(id+1), join(id, id+1);
      }
      if (mark[id]) s.insert(id);
    }
  }
  rep(i, 1, q) cout << ans[i] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}