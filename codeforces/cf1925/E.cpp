#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define rep0(a) for (ll i = 0; i < a; ++i)
#define rep1(i, a) for (ll i = 0; i < a; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b, c) for (ll i = a; i <= b; i+=c) 
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define repd0(a) for (ll i = a; i >= 1; --i)
#define repd1(i, a) for (ll i = a; i >= 1; --i)
#define repd2(i, a, b) for (ll i = b; i >= a; --i)
#define repd3(i, a, b, c) for (ll i = b; i >= a; i-=c)
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
const char nl = '\n';
const int MX = 3e5 + 10;

template<class T>
struct fenwick {
  int n;
  vector<T> t;
  fenwick (int _n):n(_n){init(n);}
  void init(int _n) {
    n=_n;
    t.assign(n+1, T{});
  }
  void update(int x, const T &v) {
    for(int i = x; i <= n; i+=i&-i) t[i] = t[i]+v;
  }
  void update(int l, int r, const T &v) {
    update(l, v); update(r+1, -v);
  }
  T query(int x) {
    T res{};
    for (int i = x; i > 0; i-=i&-i) res = res+t[i];
    return res;
  }
  T query(int l, int r) {
    return query(r) - query(l-1);
  }
  int find(const T &k) {
    int x = 0;
    T cur{};
    for (int i = 1<<(31-__builtin_clz(n)); i > 0; i>>=1) {
      if (x+i <= n && cur+t[x+i] < k) x+=i, cur+=t[x];
    }
    return x;
  }
};

ll value[MX];

void solve() {
  int n, m, q; cin >> n >> m >> q;
  fenwick<ll> fw(n);
  fenwick<int> idx(n);
  vpii P(m);
  rep(i, 0, m-1) cin >> P[i].st;
  rep(i, 0, m-1) cin >> P[i].nd;
  sort(all(P));
  vi X(m), V(m);
  rep(i, 0, m-1) X[i] = P[i].st, V[i] = P[i].nd;
  rep(i, 0, m-1) value[X[i]] = V[i];
  rep(i, 1, m-1) {
    ll n = (X[i]-X[i-1]-1);
    fw.update(X[i-1], (n)*(n+1)/2*V[i-1]);
    idx.update(X[i-1], 1);
  }
  idx.update(X[m-1], 1);
  while (q--) {
    ll op, x, y; cin >> op >> x >> y;
    if (op == 1) {
      int before = idx.find(idx.query(x))+1;
      ll n = x-before-1;
      fw.update(before, (n)*(n+1)/2*value[before] - fw.query(before, before));
      ll nxt = idx.find(idx.query(x)+1)+1;
      n = nxt-x-1;
      fw.update(x, y*(n)*(n+1)/2);
      value[x] = y;
      idx.update(x, 1);
    }
    else {
      ll ans = fw.query(x, y);
      int lx = idx.find(idx.query(x))+1, rx = idx.find(idx.query(x)+1)+1;  
      if (value[x] == 0) {
        ll n = (rx-x);
        ans += n*(n+1)/2*value[lx];
      }
      int ly = idx.find(idx.query(y))+1, ry = idx.find(idx.query(y)+1)+1; 
      ll n = (ry-y-1);
      ans -= n*(n+1)/2*value[ly];
      cout << ans << nl;
    }
  }  
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}

