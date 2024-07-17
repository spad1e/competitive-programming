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
const int MX = 5e5 + 3;

template <class T>
struct fenwick {
  int n;
  vector<T> t;
  fenwick (int n=0){init(n);}
  void init(int _n) {
    n=_n;
    t.assign(n+1, T{});
  }
  void update(int x, const T &v) {
    for(int i = x+1; i <= n; i+=i&-i) t[i] = t[i]+v;
  }
  void update(int l, int r, const T &v) {
    update(l, v); update(r+1, -v);
  }
  T query(int x) {
    T res{};
    for (int i = x+1; i > 0; i-=i&-i) res = res+t[i];
    return res;
  }
  T query(int l, int r) {
    return query(r) - query(l-1);
  }
  //find the first index that sums to >= k
  int find(const T &k) {
    int x = 0;
    T cur{};
    for (int i = 1<<(31-__builtin_clz(n)); i > 0; i>>=1)
      if (x+i <= n && cur+t[x+i] < k) x+=i, cur+=t[x];
    return x;
  }
};

int a[MX], pos[MX];
ll ans[MX], c[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  rep(i, 0, n+1) ans[i] = c[i] = 0;
  fenwick<int> fw(n+1);
  rep(i, 1, n) {
    int l1, l2, r1, r2;
    l1 = fw.find(fw.query(pos[i]));
    fw.update(l1, -1);
    l2 = fw.find(fw.query(pos[i]));
    fw.update(l1, 1);

    r1 = fw.find(fw.query(pos[i])+1);
    fw.update(r1, -1);
    r2 = fw.find(fw.query(pos[i])+1);
    fw.update(r1, 1);

    ans[0] += (ll)(pos[i]-l1)*(r1-pos[i])*i;
    ans[l1] -= (ll)(pos[i]-l1)*(r1-pos[i])*i;
    ans[r1+1] += (ll)(pos[i]-l1)*(r1-pos[i])*i;
    ans[n+1] -= (ll)(pos[i]-l1)*(r1-pos[i])*i;

    c[l1] += (ll)(pos[i]-l2-1)*(r1-pos[i])*i;
    c[r1] += (ll)(pos[i]-l1)*(r2-pos[i]-1)*i;

    ans[l1+1] += (ll)(pos[i]-l1-1)*(r1-pos[i])*i; 
    ans[pos[i]] -= (ll)(pos[i]-l1-1)*(r1-pos[i])*i; 
    ans[pos[i]+1] += (ll)(pos[i]-l1)*(r1-pos[i]-1)*i;
    ans[r1] -= (ll)(pos[i]-l1)*(r1-pos[i]-1)*i;

    fw.update(pos[i], 1);
  }
  rep(i, 1, n) ans[i] += ans[i-1];
  rep(i, 1, n) cout << ans[i]+c[i] << " \n"[i==n];
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}