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

void solve() {
  int n; cin >> n;
  vi adj[n+1];
  vi mark(n+1, 0);
  rep(i, 1, n-1) {int u, v; cin >> u >> v; adj[u].pb(v); adj[v].pb(u);}
  int k; cin >> k;
  vpii path(k+1);
  rep(i, 1, k) cin >> path[i].st >> path[i].nd;
  function<int(int, int)> dfs = [&](int i, int prt) {
    int node = 0;
    for(int j = 1; j <= k; ++j) if (path[j].st == i || path[j].nd == i) node |= 1<<(j-1);
    for (auto j : adj[i]) {
      if (j == prt) continue;
      node ^= dfs(j, i);
    }
    for (int j = 0; j < k; ++j) if (node & (1<<j)) mark[i] |= 1<<j;
    return node;
  };
  dfs(1, 0);
  vi dp(1<<k, 100);
  dp[0] = 0;
  function<void(int, int)> dfs2 = [&](int i, int prt) {
    int node = 0; bool skip = 0;
    for (auto j : adj[i]) {
      if (j == prt) continue;
      if (mark[j] == mark[i]) skip = 1;
    }
    for (auto j : adj[i]) {
      if (j == prt) continue;
      dfs2(j, i);
    }
    if (skip || mark[i] == 0) return;
    for (int j = 0; j < (1<<k); ++j) ckmin(dp[j|mark[i]], dp[j]+1);
  };
  dfs2(1, 0);
  cout << dp[(1<<k)-1] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}