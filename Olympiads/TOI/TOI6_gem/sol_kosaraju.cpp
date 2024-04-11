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
const int MX = 2e5 + 3;

pii slot[MX];
vi adj[MX], rev[MX];
int no[MX], comp[MX], cnt;
bool vis[MX];
stack<int> order;

void dfs(int i) {
  if (vis[i]) return;
  vis[i] = 1;
  trav(j, adj[i]) dfs(j);
  order.push(i);
}

void dfs2(int i, int c) {
  if (comp[i]) return;
  comp[i] = c;
  for (auto j : rev[i]) dfs2(j, c);
} 

void solve() {
  int N, M; cin >> N >> M;
  rep(i, 1, N) cin >> slot[i].st >> slot[i].nd;
  rep(i, 1, M/2) {
    int u, v; cin >> u >> v;
    no[u] = v; no[v] = u;
  }
  rep(i, 1, M) {
    adj[i].clear(), rev[i].clear();
    comp[i] = vis[i] = cnt = 0;
  }
  rep(i, 1, N) {
    auto [u, v] = slot[i];
    adj[no[u]].pb(v); adj[no[v]].pb(u);
    rev[u].pb(no[v]); rev[v].pb(no[u]);
  }
  rep(i, 1, M) dfs(i);
  while (!order.empty()) dfs2(order.top(), ++cnt), order.pop();
  rep(i, 1, M) {
    if (comp[i] == comp[no[i]]) {cout << "N"; return;}
  }
  cout << "Y";
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 5;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}