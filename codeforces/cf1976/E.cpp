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

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e5 + 10;

int l[MX], r[MX], a[MX<<1], at[MX], lc[MX<<1], rc[MX<<1], cnt=1, cnt2;
bool avail[MX];
vpii order;

void dfs(int u) {
  if (lc[u] == 0) return void(order.push_back({-a[u], ++cnt2}));
  dfs(lc[u]), dfs(rc[u]);
}

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, q) cin >> l[i];
  rep(i, 1, q) cin >> r[i];
  a[1] = n; at[n] = 1;
  rep(i, 1, q) {
    if (at[l[i]]) {
      rc[at[l[i]]] = ++cnt; a[cnt] = r[i]; at[r[i]] = cnt;
      lc[at[l[i]]] = ++cnt; a[cnt] = l[i]; at[l[i]] = cnt;
      at[l[i]] = cnt;
    }
    else {
      lc[at[r[i]]] = ++cnt; a[cnt] = l[i]; at[l[i]] = cnt;
      rc[at[r[i]]] = ++cnt; a[cnt] = r[i]; at[r[i]] = cnt;
      at[r[i]] = cnt;
    }
  }
  dfs(1);
  sort(all(order));
  int j = 0, sum = 0, sum2 = 0;
  ll ans = 1;
  repd(i, 1, n) {
    bool eq = 0;
    while (j < sz(order) && i <= -order[j].st) {
      if (!avail[order[j].nd]) avail[order[j].nd] = 1, sum++;
      if (!avail[order[j].nd-1]) avail[order[j].nd-1] = 1, sum++;
      if (i == -order[j++].st) eq = 1;
    }
    if (!eq) ans = (ans*(sum+sum2)) % MOD;
    sum2 += !eq;
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}