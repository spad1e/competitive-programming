#pragma once
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
typedef tuple<ll, ll, ll> tll3;
typedef tuple<ll, ll, ll, ll> tll4;
typedef tuple<ll, ll, ll, ll, ll> tll5;

template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define rep0(a) for (int i = 0; i < a; ++i)
#define rep1(i, a) for (int i = 0; i < a; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b, c) for (int i = a; i <= b; i+=c) 
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define repd0(a) for (int i = a; i >= 1; --i)
#define repd1(i, a) for (int i = a; i >= 1; --i)
#define repd2(i, a, b) for (int i = b; i >= a; --i)
#define repd3(i, a, b, c) for (int i = b; i >= a; i-=c)
#define repd(...) overload4(__VA_ARGS__, repd3, repd2, repd1, repd0)(__VA_ARGS__)
#define trav(a, x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
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

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1500 + 3;

int c[MX][MX], u[MX][MX], d[MX][MX], l[MX][MX], r[MX][MX];
bool vis[MX][MX];

int gap(int l1, int r1, int l2, int r2) {
  return min(r1, r2) - max(l1, l2) + 1;
}

void solve() {
  int n, m, K, L; cin >> n >> m >> K >> L;
  int xh, yh ,xv, yv; cin >> xh >> yh >> xv >> yv;
  swap(n, m); swap(xh, yh); swap(xv, yv);
  ++xh, ++yh, ++xv, ++yv;
  int xe, ye;
  rep(i, 1, n) rep(j, 1, m) {
    char ch; cin >> ch;
    if (ch=='*') xe = i, ye = j;
    c[i][j] = (ch=='X');
  }

  int idx;
  rep(i, 1, n) {
    idx = 1;
    rep(j, 1, m) {
      if (c[i][j]) idx=j+1;
      else l[i][j] = idx;
    }
    idx = m;
    repd(j, 1, m) {
      if (c[i][j]) idx=j-1;
      else r[i][j] = idx;
    }
  }
  rep(j, 1, m) {
    idx = 1;
    rep(i, 1, n) {
      if (c[i][j]) idx=i+1;
      else u[i][j] = idx;
    }
    idx = n;
    repd(i, 1, n) {
      if (c[i][j]) idx=i-1;
      else d[i][j] = idx;
    }
  }
  
  queue<pii> q;
  q.push({xh, yv});
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (vis[x][y]) continue;
    vis[x][y] = 1;

    if (y-1>0 && !c[x][y-1] && gap(u[x][y], d[x][y], u[x][y-1], d[x][y-1]) >= L) q.push({x, y-1}); 
    if (y+1<=m && !c[x][y+1] && gap(u[x][y], d[x][y], u[x][y+1], d[x][y+1]) >= L) q.push({x, y+1}); 
    if (x-1>0 && !c[x-1][y] && gap(l[x][y], r[x][y], l[x-1][y], r[x-1][y]) >= K) q.push({x-1, y}); 
    if (x+1<=n && !c[x+1][y] && gap(l[x][y], r[x][y], l[x+1][y], r[x+1][y]) >= K) q.push({x+1, y}); 
  }
  cout << (vis[xe][ye] ? "YES" : "NO") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}