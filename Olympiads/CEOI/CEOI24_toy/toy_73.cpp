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

int c[MX][MX], a[MX][MX], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool vis[MX][MX];

int query(int x1, int y1, int x2, int y2) {
  if (x1>x2) swap(x1, x2);
  if (y1>y2) swap(y1, y2);
  if (x2 >= MX) x2 = MX-1;
  if (y2 >= MX) y2 = MX-1;
  if (x1 < 0) x1 = 0;
  if (y1 < 0) y1 = 0;
  return a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1];
}

void solve() {
  int n, m, K, L; cin >> m >> n >> K >> L;
  int xh, yh ,xv, yv; cin >> xh >> yh >> xv >> yv;
  swap(xh, yh); swap(xv, yv);
  ++xh, ++yh, ++xv, ++yv;
  int xe, ye;
  rep(i, 0, n+1) c[i][0] = c[i][m+1] = 1;
  rep(j, 0, m+1) c[0][j] = c[n+1][j] = 1;
  rep(i, 1, n) rep(j, 1, m) {
    char ch; cin >> ch;
    if (ch=='*') xe = i, ye = j;
    c[i][j] = (ch=='X');
  }
  rep(i, 0, MX-1) rep(j, 0, MX-1) a[i][j] = c[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];

  queue<pii> q;
  q.push({xh, yv});
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (vis[x][y]) continue;
    vis[x][y] = 1;
    int l, r, gap;
    
    //move left
    if (!c[x][y-1]) {
      l = 0, r = MX, gap = 1;
      while (l<r) {
        int mid = (l+r+1)>>1;
        if (query(x, y, x-mid, y-1) > 0) r=mid-1;
        else l = mid; 
      }
      gap += l;
      l = 0, r = MX;
      while (l<r) {
        int mid = (l+r+1)>>1;
        if (query(x, y, x+mid, y-1) > 0) r=mid-1;
        else l = mid;
      }
      gap += l;

      if (gap >= L) q.push({x, y-1}); 
    }

    //move right
    if (!c[x][y+1]) {
      l = 0, r = MX, gap = 1;
      while (l<r) {
        int mid = (l+r+1)>>1;
        if (query(x, y, x-mid, y+1) > 0) r=mid-1;
        else l = mid; 
      }
      gap += l;
      l = 0, r = MX;
      while (l<r) {
        int mid = (l+r+1)>>1;
        if (query(x, y, x+mid, y+1) > 0) r=mid-1;
        else l = mid;
      }
      gap += l;
      if (gap >= L) q.push({x, y+1}); 
    }

    //move up
    if (!c[x-1][y]) {
      l = 0, r = MX, gap = 1;
      while (l<r) {
        int mid = (l+r+1)>>1;
        if (query(x, y, x-1, y-mid) > 0) r=mid-1;
        else l = mid; 
      }
      gap += l;
      l = 0, r = MX;
      while (l<r) {
        int mid = (l+r+1)>>1;
        if (query(x, y, x-1, y+mid) > 0) r=mid-1;
        else l = mid;
      }
      gap += l;

      if (gap >= K) q.push({x-1, y}); 
    }

    //move down
    if (!c[x+1][y]) {
      l = 0, r = MX, gap = 1;
      while (l<r) {
        int mid = (l+r+1)>>1;
        if (query(x, y, x+1, y-mid) > 0) r=mid-1;
        else l = mid; 
      }
      gap += l;
      l = 0, r = MX;
      while (l<r) {
        int mid = (l+r+1)>>1;
        if (query(x, y, x+1, y+mid) > 0) r=mid-1;
        else l = mid;
      }
      gap += l;

      if (gap >= K) q.push({x+1, y}); 
    }
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