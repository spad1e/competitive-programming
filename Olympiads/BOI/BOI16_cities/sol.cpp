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

template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

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

vpii adj[MX];
ll dp[MX][32], imp[MX];

void solve() {
  int n, k, m; cin >> n >> k >> m;
  for (int i = 0; i < k; ++i) cin >> imp[i];
  for (int i = 1; i <= m; ++i) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].pb({v, w}); adj[v].pb({u, w});
  }
  
  for (int i = 1; i <= n; ++i) for (int mask = 0; mask < 32; ++mask) dp[i][mask] = LINF;
  //base cases
  for (int i = 0; i < k; ++i) dp[imp[i]][(1<<i)] = 0;
  for (int bitmask = 0; bitmask < (1<<k); ++bitmask) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < k; ++j) {
        if (bitmask & (1<<j)) {
          ckmin(dp[i][bitmask], dp[i][bitmask^(1<<j)] + dp[i][(1<<j)]);
        }
      }
    }

    pqg<pll> pq;
    for (int i = 1; i <= n; ++i) pq.push({dp[i][bitmask], i});
    while (!pq.empty()) {
      auto [W, a] = pq.top(); pq.pop();
      if (dp[a][bitmask] < W) continue;
      for (auto [b, w] : adj[a]) {
        if (ckmin(dp[b][bitmask], dp[a][bitmask] + w)) pq.push({dp[b][bitmask], b});
      }
    }
  }

  ll ans = LINF;
  for (int i = 1; i <= n; ++i) ckmin(ans, dp[i][(1<<k)-1]);
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}

