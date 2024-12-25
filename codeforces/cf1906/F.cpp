#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int MX = 1<<18;

template<typename Node>
struct SegTree {
  int n;
  vector<Node> t;
  void init(int _n) { n = _n, t.assign(4*n, Node()); }
  void pull(int i) { t[i] = t[i<<1] + t[i<<1|1]; } 
  void update(int l, int r, int x, Node val, int i) {
    if (l==r) return void(t[i] = val);
    int mid = (l+r)>>1;
    if (x <= mid) update(l, mid, x, val, i<<1);
    else update(mid+1, r, x, val, i<<1|1);
    pull(i);
  }
  void update(int x, Node val) { update(1, n, x, val, 1); }
  Node query(int l, int r, int a, int b, int i) {
    if (a <= l && r <= b) return t[i];
    if (r < a || l > b) return Node(INT_MIN);
    int mid = (l+r)>>1;
    return query(l, mid, a, b, i<<1) + query(mid+1, r, a, b, i<<1|1);
  }
  Node query(int a, int b) { return query(1, n, a, b, 1); }
};

struct Node {
  ll sum, mxsum, mxpre, mxsuf;
  Node(int _sum=0) {
    sum = mxsum = mxpre = mxsuf = _sum;
  }
  friend Node operator+(const Node &lhs, const Node &rhs) {
    Node ret = Node(lhs.sum + rhs.sum);
    ret.mxpre = max(lhs.sum + rhs.mxpre, lhs.mxpre);
    ret.mxsuf = max(rhs.sum + lhs.mxsuf ,rhs.mxsuf);
    ret.mxsum = max({lhs.mxsum, rhs.mxsum, lhs.mxsuf + rhs.mxpre});
    return ret;
  }
};

ll val[MX], ans[MX];
vector<tuple<int, int, int>> upd[MX];
vector<tuple<int, int, int>> que[MX];

int main() {
  int n, k; cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    int l, r; cin >> l >> r >> val[i];
    upd[l].push_back({i, val[i], 0});
    upd[r+1].push_back({i, val[i], 1});
  }

  int q; cin >> q;
  for (int i = 1; i <= q; ++i) {
    int k, s, t; cin >> k >> s >> t;
    que[k].push_back({s, t, i});
  }

  SegTree<Node> t; t.init(MX);
  for (int i = 1; i <= n; ++i) {
    for (auto [idx, x, mode] : upd[i]) {
      if (mode) t.update(idx, Node(0));
      else t.update(idx, Node(x));
    }

    for (auto [l, r, idx] : que[i]) {
      ans[idx] = t.query(l, r).mxsum;
    }
 }

  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << '\n';
  }
  cout << '\n';
}