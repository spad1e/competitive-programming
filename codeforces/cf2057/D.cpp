#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

template <class Node>
struct SegmentTree {
  vector<Node> t;
  int n;
  SegmentTree(int _n) {
    n = _n;
    t.assign(n<<2, Node());
  }
  void pull(int i) { t[i] = t[i<<1] + t[i<<1|1]; }
  void update(int l, int r, int x, Node val, int idx) {
    if (l == r) return void(t[idx] = val);
    int mid = (l+r)>>1;
    if (x <= mid) update(l, mid, x, val, idx<<1);
    else update(mid+1, r, x, val, idx<<1|1);
    pull(idx);
  }
  void update(int x, Node val) { update(1, n, x, val, 1); }
  Node query(int l, int r, int a, int b, int idx) {
    if (r < a || b > l) return Node();
    if (a <= l && r <= b) return t[idx];
    int mid = (l+r)>>1;
    return query(l, mid, a, b, idx<<1) + query(mid+1, r, a, b, idx<<1|1);
  }
  Node query(int l, int r) { query(1, n, l, r, 1); }
};

struct Node {
  int mn, mx, best;
  Node(int _mn=INT_MAX, int _mx=INT_MIN, int _best=0) {
    mn = _mn, mx = _mx, best = _best;
  }
  friend Node operator+(const Node &lhs, const Node &rhs) {
    return Node(min(lhs.mn, rhs.mn), max(lhs.mx, rhs.mx), max({lhs.best, rhs.best, rhs.mx - lhs.mn})); 
  }    
};

int a[MX], p[MX], x[MX];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) cin >> a[i];
  SegmentTree<Node> t1(n), t2(n);
  rep(i, 1, n) t1.update(i, Node(a[i]-i, a[i]-i));
  rep(i, 1, n) t2.update(n-i+1, Node(a[i]+i, a[i]+i));
  cout << max(t1.t[1].best, t2.t[1].best) << '\n';
  rep(i, 1, q) {
    int p, x; cin >> p >> x; a[p] = x;
    t1.update(p, Node(a[p]-p, a[p]-p));
    t2.update(n-p+1, Node(a[p]+p, a[p]+p));
    cout << max(t1.t[1].best, t2.t[1].best) << '\n';
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}