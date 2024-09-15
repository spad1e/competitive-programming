#line 1 "/Users/pasinpornsiwakul/code/cp/library/header.hpp"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef vector<vi> vvi;
typedef tuple<int, int, int> t3;
typedef tuple<int, int, int, int> t4;
typedef tuple<int, int, int, int, int> t5;
typedef tuple<int, int, int, int, int, int> t6;
typedef tuple<ll, ll, ll> tll3;
typedef tuple<ll, ll, ll, ll> tll4;
typedef tuple<ll, ll, ll, ll, ll> tll5;
typedef tuple<ll, ll, ll, ll, ll, ll> tll6;

template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define rep0(a) for (int i = 0; i < a; ++i)
#define rep1(i, a) for (int i = 0; i < a; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b, c) for (int i = a; i <= b; i+=c) 
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define repd0(a) for (int i = a-1; i >= 0; --i)
#define repd1(i, a) for (int i = a-1; i >= 0; --i)
#define repd2(i, a, b) for (int i = b; i >= a; --i)
#define repd3(i, a, b, c) for (int i = b; i >= a; i-=c)
#define repd(...) overload4(__VA_ARGS__, repd3, repd2, repd1, repd0)(__VA_ARGS__)
#define trav(a, x) for (auto& a : x)

#define sz(x) (int)(x).size()
// #define mp make_pair
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define ins insert

template<typename T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#line 2 "tree_isomorphims_ii.cpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

vi adj[MX][2];
int sz[MX][2], cnt;
vector<int> centroid[2];
map<vector<int>, int> mp;

void find_centroid(int u, int t, int n, int prt=0) {
  bool is_centroid = 1;
  sz[u][t] = 1;
  for (auto v : adj[u][t]) {
    if (v == prt) continue;
    find_centroid(v, t, n, u);
    if (sz[v][t] > n/2) is_centroid = 0;
    sz[u][t] += sz[v][t];
  }
  if (n - sz[u][t] > n/2) is_centroid = 0;
  if (is_centroid) centroid[t].pb(u);
}

int dfs(int u, int t, int prt=0) {
  vector<int> m;
  for (auto v : adj[u][t]) {
    if (v == prt) continue;
    m.pb(dfs(v, t, u));
  }
  sort(all(m));
  if (!mp.count(m)) mp[m] = ++cnt;
  return mp[m];
}

void solve() {
  int n; cin >> n;
  rep(j, 2) rep(i, 2, n) {
    int u, v; cin >> u >> v;
    adj[u][j].pb(v), adj[v][j].pb(u);
  }
  rep(j, 2) find_centroid(1, j, n);
  bool iso = 0;
  for (auto c0 : centroid[0]) for (auto c1 : centroid[1]) {
    iso |= dfs(c0, 0) == dfs(c1, 1);
  }
  cout << (iso ? "YES" : "NO") << nl;
  rep(j, 2) rep(i, 1, n) adj[i][j].clear();
  rep(j, 2) centroid[j].clear();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}
