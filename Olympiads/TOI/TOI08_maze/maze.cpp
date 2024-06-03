/*Note: 
  testcase 1 -> chnage maze data type from bool -> int
  testcase 4, 8 -> stx, sty has wall, and is allowed to walk right out ? 
*/
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
const int MX = 150 + 10;

int maze[MX][MX], dis1[MX][MX], dis2[MX][MX];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void solve() {
  int n, m; cin >> n >> m;
  int stx, sty, enx, eny; cin >> stx >> sty >> enx >> eny;
  rep(i, 1, n) rep(j, 1, m) cin >> maze[i][j];
  rep(i, 1, n) rep(j, 1, m) dis1[i][j] = dis2[i][j] = INF;
  queue<pii> q; 

  q.push({stx, sty}); dis1[stx][sty] = 1;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    rep(i, 4) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx<1 || xx>n || yy<1 || yy>m) continue;
      if (maze[xx][yy] == 0) {
        ckmin(dis1[xx][yy], dis1[x][y] + 1);
        continue;
      }
      if (dis1[xx][yy] > dis1[x][y] + 1) {
        dis1[xx][yy] = dis1[x][y] + 1;
        q.push({xx, yy});
      }
    }
  }

  q.push({enx, eny}); dis2[enx][eny] = 1;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    rep(i, 4) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx<1 || xx>n || yy<1 || yy>m) continue;
      if (maze[xx][yy] == 0) {
        ckmin(dis2[xx][yy], dis2[x][y] + 1);
        continue;
      }
      if (dis2[xx][yy] > dis2[x][y] + 1) {
        dis2[xx][yy] = dis2[x][y] + 1;
        q.push({xx, yy});
      }
    }
  }

  int ans = 0, mn = INF;
  rep(i, 1, n) rep(j, 1, m) {
    if (dis1[i][j] != INF && dis2[i][j] != INF) ans++, ckmin(mn, dis1[i][j] + dis2[i][j] - 1);
  }
  cout << ans << nl << mn << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}