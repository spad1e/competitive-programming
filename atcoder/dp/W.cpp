#include "header.hpp"
#include "data_structure/lazysegtree.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

struct Tag{
  ll val;
  Tag(ll _val=0):val(_val){}
  void apply(int l, int r, const Tag &v) { val+=v.val; }
};
struct Node{
  ll val;
  Node(ll _val=-LINF):val(_val){}
  void apply(int l, int r, const Tag &v) { val+=v.val; }
  friend Node operator+(const Node &lhs, const Node &rhs) {
    return Node(max(lhs.val, rhs.val)); 
  }
};

vpii op[MX];
ll dp[MX];

void solve() {
  int n, m; cin >> n >> m;
  LazySegTree<Node, Tag> t(vector<ll>(n+3, 0));
  while (m--) {
    int l, r, a; cin >> l >> r >> a;
    op[l].pb({l, a}); op[r+1].pb({l, -a});
  }
  ll ans = 0;
  rep(i, 1, n) {
    for (auto [idx, c] : op[i]) t.update(1, idx, Tag(c));
    dp[i] = t.query(1, i).val;
    t.update(i+1, i+1, Tag(dp[i]));
    ckmax(ans, dp[i]);
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}