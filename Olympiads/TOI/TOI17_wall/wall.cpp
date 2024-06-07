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
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

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
const int MX = 1e3 + 10;

char a[MX][MX];
bool flood[MX][MX], mark[MX][MX];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  queue<pii> q;
  q.push({1, 1});
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if (flood[x][y]) continue;
    flood[x][y] = 1;
    rep(i, 4) {
      int xx = x+dx[i], yy = y+dy[i];
      if (xx<1 || xx>n || yy<1 || yy>m) continue;
      if (a[xx][yy] == 'X') continue;
      q.push({xx, yy});
    }
  }

  int ans = 0;
  rep(i, 1, n) rep(j, 1, m) {
    if (mark[i][j] || a[i][j] != 'X') continue;  
    int cnt = 0;
    q.push({i, j});
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (mark[x][y]) continue;
      mark[x][y] = 1;
      rep(k, 4) {
        int xx = x+dx[k], yy = y+dy[k];
        if (xx<1 || xx>n || yy<1 || yy>m) continue;
        if (flood[xx][yy]) cnt++;
        if (a[xx][yy] == 'X') q.push({xx, yy});
      }
    }
    ckmax(ans, cnt);
  }
  cout << ans << nl;
} 


int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}