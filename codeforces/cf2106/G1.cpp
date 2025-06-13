#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

vector<int> adj[MX];
int a[MX];

int ask1(vector<int> &a) {
  cout << "? 1 " << a.size() << " ";
  for (auto x : a) cout << x << " "; 
  cout << nl; cout.flush();
  int s; cin >> s;
  return s;
}

void ask2(int i) {
  cout << "? 2 " << i << nl; cout.flush();
}

int find_par(int u) {
  vector<int> q;
  for (auto v : adj[u]) q.pb(v);
  q.pb(u);
  int l = 0, r = q.size()-1;
  while (l < r) {
    int mid = (l+r)>>1;
    vector<int> v;
    rep(i, 0, mid) v.pb(q[i]);
    int s1 = ask1(v);
    ask2(u);
    int s2 = ask1(v);
    if (abs(s1 - s2) == 2*(mid+1)) l = mid+1;
    else r = mid;
  }
  return q[l];
}

void fill_ans(int u, int prt, int val) {
  vector<int> v = {u};
  a[u] = ask1(v) - val;
  for (auto v : adj[u]) {
    if (v != prt) fill_ans(v, u, val+a[u]);
  }
} 

void solve() {
  int n; cin >> n;
  rep(i, 1, n) adj[i].clear();
  rep(i, 2, n) { 
    int u, v; cin >> u >> v; 
    adj[u].pb(v); adj[v].pb(u);
  }
  int root = find_par(1);
  fill_ans(root, 0, 0);
  cout << "! ";
  rep(i, 1, n) cout << a[i] << " ";
  cout << nl; cout.flush();
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}