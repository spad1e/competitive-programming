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
const int MX = 26;

set<int> adj[MX];
int cur;
bool vis[MX];

void dfs(int i, int s, int t) {
  vis[i] = 1;
  for (auto j : adj[i]) {
    if (i == s && j == t) continue;
    if (j == s && i == t) continue;
    if (!vis[j]) dfs(j, s, t);
  }
}

bool ckbridge(int u, int v) {
  rep(i, 0, MX-1) vis[i] = 0;

  dfs(v, v, u);
  
  return vis[u];
} 

bool walk() {
  if (sz(adj[cur]) == 0) return false;
  int next = -1;
  for (auto u : adj[cur]) {
    if (ckbridge(cur, u)) next = u;
  }
  if (next == -1) next = *adj[cur].begin();
  adj[cur].erase(next);
  adj[next].erase(cur);
  cur = next;
  return true;
}

void solve() {
  int n; cin >> n;
  rep(i, 0, n-1) {
    string s; cin >> s;
    int u = s[0]-'A', v = s[1]-'A';
    adj[u].ins(v); adj[v].ins(u); 
  }

  rep(i, 0, MX-1) {
    if (sz(adj[i]) % 2) cur = i;
  }
  do { 
    cout << (char)(cur+'A') << " "; 
  } while (walk());
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}