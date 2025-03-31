#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

struct median {
  multiset<int, greater<int>> l;
  multiset<int> r;
  void insert(int x) {
    if (l.empty() || x <= *l.begin()) l.insert(x);
    else r.insert(x);
    balance();
  }
  void erase(int x) {
    if (x <= *l.begin()) l.erase(l.find(x));
    else r.erase(r.find(x));
    balance();
  }
  void balance() {
    if (l.size() < r.size()) {
      l.insert(*r.begin());
      r.erase(r.begin());
    } 
    if (l.size() > r.size()+1) {
      r.insert(*l.begin());
      l.erase(l.begin());
    }
  }
  int get_median() { return *l.begin(); }
} m;

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> a[i];
  rep(i, 0, k-1) m.insert(a[i]);
  rep(i, k, n) {
    m.erase(a[i-k]);
    m.insert(a[i]);
    cout << m.get_median() << " ";
  }
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
