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
const int MX = 1e2 + 10;

int p[MX];
vpii adj[MX];
int dis[MX][MX][2];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> p[i];
  int s, d, f; cin >> s >> d >> f;
  int m; cin >> m;
  rep(i, 1, m) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].pb({v, w}); adj[v].pb({u, w});
  }
  memset(dis, 0x3f, sizeof(dis));

  pqg<pair<int, t3>> pq;
  dis[s][0][0] = 0;
  pq.push({dis[s][0][0], {s, 0, 0}});
  while (!pq.empty()) {
    auto [a, curf, skip] = pq.top().nd; pq.pop();
    //add fuel normally
    if (curf < f && dis[a][curf+1][skip] > dis[a][curf][skip] + p[a]) {
      dis[a][curf+1][skip] = dis[a][curf][skip] + p[a];
      pq.push({dis[a][curf+1][skip], {a, curf+1, skip}});
    }
    //add fuel by gift card
    if (!skip && dis[a][f][1] > dis[a][curf][skip]) {
      dis[a][f][1] = dis[a][curf][skip];
      pq.push({dis[a][f][1], {a, f, 1}});
    }
    //move to other node
    for (auto [b, w] : adj[a]) {
      if (curf >= w && dis[b][curf-w][skip] > dis[a][curf][skip]) {
        dis[b][curf-w][skip] = dis[a][curf][skip];
        pq.push({dis[b][curf-w][skip], {b, curf-w, skip}});
      }
    }
  }
  cout << dis[d][f][1] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}