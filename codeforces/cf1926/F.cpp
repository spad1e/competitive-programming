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
const int MX = 1e5 + 3;

pii pos1[13] = {{1, 1}, {1, 3}, {1, 5}, {2, 2}, {2, 4}, {3, 1}, {3, 3}, {3, 5}, {4, 2}, {4, 4}, {5, 1}, {5, 3}, {5, 5}};
pii pos2[12] = {{1, 2}, {1, 4}, {2, 1}, {2, 3}, {2, 5}, {3, 2}, {3, 4}, {4, 1}, {4, 3}, {4, 5}, {5, 2}, {5, 4}};
int grid[7][7];

bool valid(int g[7][7], bool odd) {
  rep(i, 1, 5) {
    rep(j, 1, 5) {
      if ((i+j) % 2 != odd) continue;
      if (g[i][j] && g[i-1][j-1] && g[i-1][j+1] && g[i+1][j-1] && g[i+1][j+1]) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  rep(i, 0, 6) {
    rep(j, 0, 6) {
      char c; cin >> c;
      grid[i][j] = (c=='B');
    }
  }
  int ans1 = 5, ans2 = 5;
  rep(i, 0, 8191) {
    vector<int> v;
    rep(j, 0, 12) {
      if (i & (1<<j) && grid[pos1[j].st][pos1[j].nd]) {
        v.pb(j);
        grid[pos1[j].st][pos1[j].nd] = 0;
      }
    }
    if (valid(grid, 0)) ckmin(ans1, __builtin_popcount(i));
    trav(j, v) {
      grid[pos1[j].st][pos1[j].nd] = 1;
    }
  }
  rep(i, 0, 4095) {
    vector<int> v;
    rep(j, 0, 11) {
      if (i & (1<<j) && grid[pos2[j].st][pos2[j].nd]) {
        v.pb(j);
        grid[pos2[j].st][pos2[j].nd] = 0;
      }
    }
    if (valid(grid, 1)) ckmin(ans2, __builtin_popcount(i));
    trav(j, v) {
      grid[pos2[j].st][pos2[j].nd] = 1;
    }
  }
  cout << ans1 + ans2 << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}