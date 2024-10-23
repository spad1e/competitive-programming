#include "header.hpp"
#include "data_structure/segmenttree.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

struct minNode {
  int val;
  minNode(int x=INF) : val(x) {}
  void apply(int l, int r, int x) {val = x;}
  friend minNode operator + (const minNode &lhs, const minNode &rhs) {
    return minNode(min(lhs.val, rhs.val));
  }
};

struct maxNode {
  int val;
  maxNode(int x=-INF) : val(x) {}
  void apply(int l, int r, int x) {val = x;}
  friend maxNode operator + (const maxNode &lhs, const maxNode &rhs) {
    return maxNode(max(lhs.val, rhs.val));
  }
};

void solve() {
  int n; cin >> n;
  vi a(n);
  for (auto &x : a) cin >> x;
  SegTree<minNode> tmn(a);
  SegTree<maxNode> tmx(a);
  set<int> s;
  rep(i, n-1) if (a[i] > a[i+1]) s.ins(i);
  auto print = [&]() {
    if (s.empty()) return void(cout << "-1 -1\n");
    int L, R;
    int mn = tmn.query(*s.begin()+1, *s.rbegin()+2).val;
    int mx = tmx.query(*s.begin()+1, *s.rbegin()+2).val;
    
    cout << tmx.findfirst(1, n, [&](maxNode n){ return n.val > mn; }) << " ";
    cout << tmn.findlast(1, n, [&](minNode n){ return n.val < mx; }) << nl;
  };
  print();
  int q; cin >> q;
  while (q--) {
    int x, y; cin >> x >> y;
    tmx.update(x, y), tmn.update(x, y);
    a[--x] = y; 
    if (x > 0 && a[x-1] > a[x]) s.ins(x-1);
    if (x < n-1 && a[x] > a[x+1]) s.ins(x);
    if (x > 0 && a[x-1] <= a[x]) s.erase(x-1);
    if (x < n-1 && a[x] <= a[x+1]) s.erase(x);
    print();
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}