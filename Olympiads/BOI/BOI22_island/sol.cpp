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
#define int ll

template<typename T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int ans[MX], s[MX], prt[MX], S[MX], order[MX];
pll sorted[MX];
vi adj[MX], to_update[MX];
set<pll> to_explore[MX];

int f(int i) {return prt[i] == i ? i : prt[i] = f(prt[i]);}

void update(int i) {
  for (auto j : to_update[i]) {
    if (ans[j] == 0) continue;
    ans[j] = 0; update(j); 
  }
}

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) {
    cin >> s[i]; 
    S[i] = s[i];
    prt[i] = i;
    ans[i] = 1;
    sorted[i] = {s[i], i};
  }
  rep(i, 1, m) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }
  sort(sorted+1, sorted+n+1);
  rep(i, 1, n) order[sorted[i].nd] = i;
  rep(i, 1, n) {
    int a = sorted[i].nd;
    for (auto b : adj[a]) {
      int fa = f(a), fb = f(b);
      if (order[b] < order[a] && fa != fb) {
        S[fa] += S[fb];
        prt[fb] = prt[fa];
        if (to_explore[a].size() < to_explore[b].size()) swap(to_explore[a], to_explore[b]);
        for (auto c : to_explore[b]) to_explore[a].ins(c);
      }
    }
    int current_sum = S[f(a)];
    while (!to_explore[a].empty() && current_sum >= (*to_explore[a].begin()).st) {
      auto B = (*to_explore[a].begin()); to_explore[a].erase(B);
      int b = B.nd;
      int fa = f(a), fb = f(b);
      if (order[b] < order[a] && fa != fb) {
        S[fa] += S[fb];
        prt[fb] = prt[fa];
        if (to_explore[a].size() < to_explore[b].size()) swap(to_explore[a], to_explore[b]);
        for (auto c : to_explore[b]) to_explore[a].ins(c);
      }
      current_sum = S[f(a)];
    }
    int cnt = 0;
    for (auto b : adj[a]) if (S[b] <= current_sum) cnt++;
    for (auto b : adj[a]) {
      if (order[b] < order[a]) continue;
      if (s[b] <= current_sum) to_update[b].pb(a);
      to_explore[a].ins({S[b], b});
    }
    if (!cnt && order[a] != n) ans[a] = 0, update(a);
  }
  rep(i, 1, n) cout << ans[i];
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}