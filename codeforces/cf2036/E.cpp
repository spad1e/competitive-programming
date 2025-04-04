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
#line 2 "E.cpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, k, q; cin >> n >> k >> q;
  vvi a(n+1, vi(k+1, 0)), b(k+1, vi(n+1, 0));
  rep(i, 1, n) rep(j, 1, k) cin >> a[i][j];
  rep(i, 2, n) rep(j, 1, k) a[i][j] |= a[i-1][j];
  rep(i, 1, n) rep(j, 1, k) b[j][i] = a[i][j];

  while (q--) {
    int m; cin >> m;
    vector<pii> les, gre;
    rep(i, 1, m) {
      int r, v; char c; cin >> r >> c >> v;
      if (c == '<') les.pb({r, v});
      else gre.pb({r, v});
    }
    int least = 1;
    for (auto [r, v] : gre) {
      int idx = ub(all(b[r]), v) - b[r].begin();
      ckmax(least, idx);
    }
    least -= (least > n);
    bool ok = 1;
    for (auto [r, v] : gre) if (a[least][r] <= v) ok = 0;
    for (auto [r, v] : les) if (a[least][r] >= v) ok = 0;
    cout << (ok ? least : -1) << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
