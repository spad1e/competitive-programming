#include "header.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, k; cin >> n >> k;
  ordered_set s;
  rep(i, 1, n) s.insert(i);
  int i = 0;
  while (n--) {
    i = (i + k) % (n+1);
    auto it = s.find_by_order(i);
    cout << *it << " ";
    s.erase(it);
  };
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}