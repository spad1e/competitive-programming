/*Note: order of loop matters, loop d first then (x, y) for center will get AC
  otherwise, loop (x, y) first then d will get TLE
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

const int MOD = 1e6 + 3;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e3 + 10;

const int shift = 600;
char grid[MX][MX];
int choose[MX][MX], qs[MX][MX], qs2[MX][MX];

void solve() {
  int r, c, k; cin >> r >> c >> k;  
  rep(i, 1, r) rep(j, 1, c) cin >> grid[shift+i][shift+j];
  rep(i, 1, MX-1) rep(j, 1, MX-1) qs[i][j] = qs[i-1][j-1] + (grid[i][j] == '#');
  rep(i, 1, MX-1) rep(j, 1, MX-1) qs2[i][j] = qs2[i-1][j+1] + (grid[i][j] == '#');

  rep(i, MX) choose[i][0] = 1;
  rep(i, 1, MX - 1) rep(j, 1, i) choose[i][j] = (choose[i-1][j] + choose[i-1][j-1])%MOD;

  int ans = 0;
  rep(d, 1, r+c) rep(i, 1, r) rep(j, 1, c) {
    int x = shift+i, y = shift+j;
    int cnt = (qs[x+d][y] - qs[x][y-d]) + (qs[x-1][y+d-1] - qs[x-d-1][y-1]) + (qs2[x+d-1][y+1] - qs2[x-1][y+d+1]) + (qs2[x][y-d] - qs2[x-d][y]);
    ans = (ans + choose[cnt][k])%MOD;
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