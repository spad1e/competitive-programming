#pragma GCC optimize("O3")
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

const int MOD = 998244353;
const char nl = '\n';
const int MX = 2e5 + 3;

ll modmul(ll a,ll b,ll mod){
    ll res=(a*b-ll(1.l*a*b/mod)*mod)%mod;
    if(res<0)res+=mod;
    return res;
}
ll modinv(ll a, ll b) {
  ll x=0,x1=1;
  while(a!=0){
    ll q=b/a;
    b-=q*a; x-=q*x1;
    swap(a,b); swap(x,x1);
  }
  return x;
}
template<ll M>
struct Mint {
  ll x;
  constexpr Mint():x(0){}
  constexpr Mint(ll x):x(norm(x%getMod())){}
  static ll Mod;
  constexpr static ll getMod() {return M>0?M:Mod;}
  constexpr static void setMod(ll Mod_) {Mod=Mod_;}
  constexpr ll norm(ll x) const {if(x<0)x+=getMod(); if(x>=getMod())x-=getMod(); return x;}
  explicit constexpr operator ll()const{return x;}
  constexpr Mint operator-()const {Mint res; res.x=norm(-x); return res;}
  constexpr Mint inv()const{return modinv(x, getMod());}
  constexpr Mint &operator+=(const Mint &rhs) {x=norm(x+rhs.x); return *this;}
  constexpr Mint &operator-=(const Mint &rhs) {x=norm(x-rhs.x); return *this;}
  constexpr Mint &operator*=(const Mint &rhs) {x=modmul(x, rhs.x, getMod()); return *this;}
  constexpr Mint &operator/=(const Mint &rhs) {x=modmul(x, rhs.inv().x, getMod()); return *this;}
  constexpr Mint &operator++(){return *this+=1;}
  constexpr Mint &operator--(){return *this-=1;}
  constexpr Mint operator++(int) {Mint res=*this; *this+=1; return res;}
  constexpr Mint operator--(int) {Mint res=*this; *this-=1; return res;}
  friend constexpr Mint operator+(Mint lhs, const Mint &rhs) {return lhs+=rhs;}
  friend constexpr Mint operator-(Mint lhs, const Mint &rhs) {return lhs-=rhs;}
  friend constexpr Mint operator*(Mint lhs, const Mint &rhs) {return lhs*=rhs;}
  friend constexpr Mint operator/(Mint lhs, const Mint &rhs) {return lhs/=rhs;} 
  friend istream &operator>>(istream &is, Mint &o) {ll x{}; is>>x; o=Mint(x); return is;}
  friend ostream &operator<<(ostream &os, const Mint &o) {return os<<o.x;}
  friend constexpr bool operator==(const Mint &lhs, const Mint &rhs) {return lhs.x==rhs.x;}
  friend constexpr bool operator!=(const Mint &lhs, const Mint &rhs) {return lhs.x!=rhs.x;}
  friend constexpr bool operator<(const Mint &lhs, const Mint &rhs) {return lhs.x<rhs.x;}
};
template<>
ll Mint<0ll>::Mod=ll(1e18)+9;
using mint = Mint<MOD>;
using vm = vector<mint>;

template<class T>
struct fenwick {
  int n;
  vector<T> t;
  fenwick (){}
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
    if (x > n) x = n;
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
      if (x+i <= n && cur+t[i] < k) x+=i, cur+=t[i];
    }
    return x;
  }
};

ll p[MX], q[MX];

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> p[i];
  rep(i, 1, k) cin >> q[i];
  mint ans = 0;
  fenwick<int> f;
  f.init(k+10);
  rep(i, 1, k) {
    ans += f.query(q[i]+1, 2*k);
    f.update(q[i]+1, 1);
  }
  ans *= n;
  vector<fenwick<int>> fw(21);
  trav(i, fw) i.init(4*n+2);
  rep(i, 1, n) {
    ll m = k; ll add = m*(m+1)/2;
    rep(j, 0, 20) {
      int cnt = fw[j].query(p[i], 2*p[i]);
      ans += cnt*add;
      add -= (m-j);
      add = max(add, 0ll);
    }
    add = m*(m+1)/2 + (--m);
    rep(j, 1, 20) {
      if (p[i]<<j > 2*n) break;
      int cnt = fw[0].query(p[i]<<j, p[i]<<(j+1));
      ans += cnt*add;
      if (m == 0) m = 1;
      add += (--m);
    }
    rep(j, 0, min(k-1, 20)) {
      if (p[i]<<j > 4*n) break;
      fw[j].update(p[i]<<j, 1);
    }
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}

