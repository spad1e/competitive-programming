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
const int MX = 1e5 + 10;

pii pt[MX];

double dis(pii a, pii b) {
  return sqrt((ll)(a.st-b.st)*(a.st-b.st) + (ll)(a.nd-b.nd)*(a.nd-b.nd));
}

float cpop (int l, int r) {
  if (r-l <= 3) {
    double ret = INF;
    rep(i, l, r) rep(j, i+1, r) ckmin(ret, dis(pt[i], pt[j]));
    return ret;
  }

  int m = (l+r)/2;
  double ret = min(cpop(l, m), cpop(m+1, r));
  vi filter;
  rep(i, l, r) if (abs(pt[i].st - pt[m].st) < ret) filter.pb(i);
  sort(all(filter), [&](int a, int b) { return pt[a].nd < pt[b].nd; });
  int s = sz(filter);
  rep(i, 0, s-1) {
    rep(j, i+1, s-1) {
      if (pt[filter[j]].nd - pt[filter[i]].nd >= ret) break;
      ckmin(ret, dis(pt[filter[i]], pt[filter[j]]));
    }
  }
  return ret;
}

void solve() {
  int n, r, d; cin >> n >> r >> d;
  rep(i, 1, n) cin >> pt[i].st >> pt[i].nd;
  sort(pt+1, pt+n+1);
  cout << (cpop(1, n) >= d+2*r ? "Y" : "N") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}