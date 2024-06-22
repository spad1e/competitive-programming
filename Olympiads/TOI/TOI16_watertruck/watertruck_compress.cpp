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
typedef tuple<ll, ll, ll> t3;
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

vector<pii> adj[MX];
vector<t3> adj2[MX], adj3[MX];
bool mark[MX], mark2[MX];
int deg[MX], mark3[MX];
int m, n, cnt2, cnt3, ans, ans_bruteforce = INF;

void clear_deg1() {
  queue<int> q;
  rep(i, n) if (deg[i] == 1) q.push(i);
  while (!q.empty()) {
    int i = q.front(); q.pop();
    if (i == 0) continue;
    mark[i] = 1;
    auto [j, w] = adj[i][0];
    ans += 2*w;
    if (--deg[j] == 1) q.push(j);
  }
  rep(i, n) {
    if (mark[i]) continue;
    for (auto [j, w] : adj[i]) {
      if (mark[j] || j<i) continue;
      cnt2++;
      adj2[i].pb({j, w, cnt2}); adj2[j].pb({i, w, cnt2});
    }
  }
}

pii compress(int i, int w, int prt) {
  if (sz(adj2[i]) != 2 || i == 0) return {i, w};
  for (auto [j, ww, idx] : adj2[i]) {
    if (j == prt) continue;
    mark2[idx] = 1;
    return compress(j, w+ww, i);
  }
}

void compress_deg2() {
  rep(i, n) {
    if (sz(adj2[i]) == 2 && i != 0) continue;
    for (auto [j, w, idx] : adj2[i]) {
      if (mark2[idx]) continue;
      mark2[idx] = 1;
      auto [t, ww] = compress(j, w, i);
      cnt3++;
      adj3[i].pb({t, ww, cnt3}); adj3[t].pb({i, ww, cnt3});
    }
  } 
}

void brute_force(int i, int t, int d) {
  if (i == 0 && t == 0) return void(ckmin(ans_bruteforce, d));
  if (d >= ans_bruteforce) return;
  for (auto [j, w, idx] : adj3[i]) {
    if (mark3[idx] == 2) continue;
    mark3[idx]++;
    brute_force(j, t-(mark3[idx]==1), d+w); 
    mark3[idx]--;
  }
}

void solve() {
  cin >> m >> n;
  rep(i, 1, m) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].pb({v, w}); adj[v].pb({u, w});
    deg[u]++, deg[v]++;
  }
  clear_deg1();
  compress_deg2();
  brute_force(0, cnt3, 0);
  cout << ans + ans_bruteforce << nl;
}  

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}