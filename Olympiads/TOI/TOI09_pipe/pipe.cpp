/*Note: order matters -> entrance from top, bottom, left then right
  Note: if shuffle the order, the answer will be wrong -> 60 points
  Note: if change order to -> entrance from left, right, top, bottom, the answer will be wrong -> 80 points
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
const int MX = 3e2 + 10;

int cell[MX][MX], mark[MX][MX];
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) cin >> cell[i][j];

  vi ans;
  //directions: 0 - right to left, 1 - down to up, 2 - left to right, 3 - up to down
  function<void(int, int, int, int)> walk = [&](int x, int y, int dir, int d) {
    if (x<1 || x>n || y<1 || y>m) {
      ans.pb(d);
      return;
    }

    if (cell[x][y] == 11) dir = (dir==1?0:3);
    else if (cell[x][y] == 12) dir = (dir==1?2:3);
    else if (cell[x][y] == 13) dir = (dir==3?0:1);
    else if (cell[x][y] == 14) dir = (dir==3?2:1);
    
    if (dir == 0 || dir == 2) mark[x][y] |= 1;
    else mark[x][y] |= 2;
    
    walk(x+dx[dir], y+dy[dir], dir, d+1);
  };

  rep(j, 1, m) if ((cell[1][j] == 11 || cell[1][j] == 12 || cell[1][j] == 21 || cell[1][j] == 31) && !(mark[1][j] & 2)) walk(1, j, 1, 0);
  rep(j, 1, m) if ((cell[n][j] == 13 || cell[n][j] == 14 || cell[n][j] == 21 || cell[n][j] == 31) && !(mark[n][j] & 2)) walk(n, j, 3, 0);
  rep(i, 1, n) if ((cell[i][1] == 11 || cell[i][1] == 13 || cell[i][1] == 22 || cell[i][1] == 31) && !(mark[i][1] & 1)) walk(i, 1, 2, 0);
  rep(i, 1, n) if ((cell[i][m] == 12 || cell[i][m] == 14 || cell[i][m] == 22 || cell[i][m] == 31) && !(mark[i][m] & 1)) walk(i, m, 0, 0);
  
  cout << sz(ans) << nl; 
  trav(x, ans) cout << x << " ";
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}