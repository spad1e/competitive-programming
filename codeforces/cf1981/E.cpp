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
const int MX = 5e5 + 10;

int l[MX], r[MX], a[MX], pa[MX];

int f(int i) {
  return pa[i]==i ? i : pa[i]=f(pa[i]);
}

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> l[i] >> r[i] >> a[i];
  vpii proc;
  vector<t3> edges;
  rep(i, 1, n) proc.pb({l[i], i}), proc.pb({r[i]+1, -i});
  sort(all(proc));
  set<pii> s;
  for (auto [i, cur] : proc) {
    if (!s.empty() && cur > 0) {
      auto itg = s.lb({a[cur], -INF});
      if (itg != s.end()) {
        pii g = *itg;
        edges.pb({g.st-a[cur], cur, g.nd});
        auto it = s.lb({a[cur], -INF});
      }
      auto itl = s.lb({a[cur], -INF});
      if (itl != s.begin()) {
        pii l = *--itl;
        edges.pb({a[cur]-l.st, cur, l.nd});
      }
    }
    if (cur > 0) s.ins({a[cur], cur});
    else s.erase({a[-cur], -cur});
  }

  sort(all(edges));
  ll cnt = 0, ans = 0;
  rep(i, 1, n) pa[i] = i;
  for (auto [w, u, v] : edges) {
    if (f(u) != f(v)) {
      cnt++, ans += w;
      pa[f(u)] = f(v);
    }
  }
  cout << (cnt == n-1 ? ans : -1) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}