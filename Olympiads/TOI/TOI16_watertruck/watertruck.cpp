/*Note: The first testcase gave the wrong V value, should be 9 instead of 8.

Correct input:
9 9
0 3 1
3 5 2
5 4 4
4 2 3
2 1 4
1 5 6
6 3 7
6 7 5
6 8 6
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
typedef tuple<int, int, int> t3;
typedef tuple<int, int, int, int> t4;
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
const int MX = 1e5 + 10;

vector<t3> adj[MX];
int deg[MX], dis[MX], cnt, ans, t;
bool removed[MX];

int dijkstra(int s, int e) {
  memset(dis, 0x3f, sizeof(dis));
  pqg<pii> pq; pq.push({dis[s]=0, s});
  while (!pq.empty()) {
    auto [d, a] = pq.top(); pq.pop();
    if (d > dis[a]) continue;
    for (auto [b, w, idx] : adj[a]) {
      if (removed[idx]) continue;
      if (ckmin(dis[b], d+w)) pq.push({dis[b], b});
    }
  }
  return dis[e];
}

void solve() {
  int m, n; cin >> m >> n;
  rep(i, 1, m) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].pb({v, w, i}); adj[v].pb({u, w, i});
    deg[u]++; deg[v]++;
    ans += w;
  }

  queue<int> q;
  rep(i, n) if (deg[i] == 1) q.push(i);
  while (!q.empty()) {
    int a = q.front(); q.pop();
    for (auto [b, w, idx] : adj[a]) {
      if (removed[idx]) continue;
      removed[idx] = 1;
      ans += w; deg[a]--;
      if (--deg[b] == 1) q.push(b);
    }
  }

  vi deg3;
  rep(i, n) if (deg[i] == 3) deg3.pb(i);
  if (sz(deg3) == 2) ans += dijkstra(deg3[0], deg3[1]);
  else if (sz(deg3) == 4) {
    int mn=INF, a[4]={0, 1, 2, 3};
    rep(j, 1, 3) {
    swap(a[1], a[j]);
      ckmin(mn, dijkstra(deg3[a[0]], deg3[a[1]]) + dijkstra(deg3[a[2]], deg3[a[3]]));
    }
    ans += mn;
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