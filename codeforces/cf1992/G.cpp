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
typedef tuple<int, int, int, int, int> t5;
typedef tuple<ll, ll, ll> tll3;
typedef tuple<ll, ll, ll, ll> tll4;
typedef tuple<ll, ll, ll, ll, ll> tll5;

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
const int MX = 1e5 + 3;

ll fac[MX], inv[MX];

int binpow(int a, int b) {
  if (b==0) return 1;
  ll ret = binpow(a, b/2);
  if (b&1) return ret*ret%MOD*a%MOD;
  return ret*ret%MOD;
}

void initfac() {
  fac[0] = 1;
  rep(i, 1, MX-1) fac[i] = i*fac[i-1]%MOD;
  inv[MX-1] = binpow(fac[MX-1], MOD-2);
  repd(i, 0, MX-2) inv[i] = (i+1)*inv[i+1]%MOD;
}

ll choose(int n, int r) {
  if (r>n || n<0 || r<0) return 0;
  return fac[n]*inv[n-r]%MOD*inv[r]%MOD;
}

void solve() {
  int n; cin >> n;
  ll ans = 0;
  rep(s, 0, n) rep(mex, s+1, 2*s+1) {
    ll cnt = choose(min(n, mex-1), mex-s-1)*choose(n-mex, 2*s-mex+1)%MOD;
    if (2*s-mex+1 == 0) cnt = choose(min(n, mex-1), mex-s-1);
    ans = (ans + cnt*mex%MOD) % MOD;
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  initfac();
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}