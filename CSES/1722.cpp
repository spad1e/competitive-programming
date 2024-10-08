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
struct Mint{
  ll x;
  constexpr Mint():x(0){}
  constexpr Mint(ll x):x(norm(x%getMod())){}
  static ll Mod;
  constexpr static ll getMod(){return M>0?M:Mod;}
  constexpr static void setMod(ll Mod_){Mod=Mod_;}
  constexpr ll norm(ll x)const{if(x<0)x+=getMod();if(x>=getMod())x-=getMod();return x;}
  explicit constexpr operator ll()const{return x;}
  constexpr Mint operator-()const{Mint res;res.x=norm(-x);return res;}
  constexpr Mint inv()const{return modinv(x,getMod());}
  constexpr Mint &operator+=(const Mint &rhs){x=norm(x+rhs.x);return *this;}
  constexpr Mint &operator-=(const Mint &rhs){x=norm(x-rhs.x);return *this;}
  constexpr Mint &operator*=(const Mint &rhs){x=modmul(x,rhs.x,getMod());return *this;}
  constexpr Mint &operator/=(const Mint &rhs){x=modmul(x,rhs.inv().x,getMod());return *this;}
  constexpr Mint &operator++(){return *this+=1;}
  constexpr Mint &operator--(){return *this-=1;}
  constexpr Mint operator++(int){Mint res=*this;*this+=1;return res;}
  constexpr Mint operator--(int){Mint res=*this;*this-=1;return res;}
  friend constexpr Mint operator+(Mint lhs,const Mint &rhs){return lhs+=rhs;}
  friend constexpr Mint operator-(Mint lhs,const Mint &rhs){return lhs-=rhs;}
  friend constexpr Mint operator*(Mint lhs,const Mint &rhs){return lhs*=rhs;}
  friend constexpr Mint operator/(Mint lhs,const Mint &rhs){return lhs/=rhs;}
  friend istream &operator>>(istream &is,Mint &o){ll x{};is>>x;o=Mint(x);return is;}
  friend ostream &operator<<(ostream &os,const Mint &o){return os<<o.x;}
  friend constexpr bool operator==(const Mint &lhs,const Mint &rhs){return lhs.x==rhs.x;}
  friend constexpr bool operator!=(const Mint &lhs,const Mint &rhs){return lhs.x!=rhs.x;}
  friend constexpr bool operator<(const Mint &lhs,const Mint &rhs){return lhs.x<rhs.x;} // for std::map
};
template<>
ll Mint<0ll>::Mod=ll(1e18)+9;
using mint = Mint<MOD>;
using vm = vector<mint>;
mint invmod(int x){
  static vm invs{0,1};
  for(int i=sz(invs);i<=x;i++)
    invs.push_back(-MOD/i*invs[MOD%i]);
  return invs[x];
}

template<class T>
struct Matrix {
  int n, m;
  vector<vector<T>> M;
  Matrix() {}
  Matrix(int _n, int _m) {n=_n; m=_m; M.assign(n, vector<T>(m, T{}));}
  Matrix(vector<vector<T>> a) {n=a.size(); m=n?a[0].size():0; M=a;}
  static inline Matrix<T> identity(int n) {
    Matrix ans = Matrix(n, n);
    for (int i = 0; i < n; ++i) ans[i][i] = 1;
    return ans;
  }

  inline Matrix operator + (const Matrix &other) {
    assert(n==other.n && m==other.m);
    Matrix ans = Matrix(n, m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] += M[i][j] + other[i][j];
    return ans;
  }

  inline Matrix operator - (const Matrix &other) {
    assert(n==other.n && m==other.m);
    Matrix ans = Matrix(n, m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] -= M[i][j] + other[i][j];
    return ans;
  }

  inline Matrix operator % (const int MOD) {
    Matrix ans = Matrix(n, m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] = M[i][j] % MOD;
    return ans;
  }

  inline Matrix operator * (const Matrix &other) {
    assert(m == other.m);
    Matrix ans = Matrix(n, other.m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < other.m; ++k) ans[i][k] += M[i][j]*other[j][k];
    return ans; 
  }

  inline Matrix operator = (const vector<vector<T>> v) {
    n = v.size();
    m = (n > 0) ? v[0].size() : 0;
    M = v;
    return *this;
  }

  inline Matrix pow(long long b) {
    assert(n==m);
    Matrix a(M);
    Matrix res = Matrix<T>::identity(n);
    for (;b>0;b >>= 1, a*=a) if (b&1) res *= a;
    return res;
  }

  inline vector<T>& operator [] (const int i) {
    return M[i];
  }

  const inline vector<T>& operator [] (const int i) const {
    return M[i];
  }

  inline Matrix& operator += (const Matrix& other) {return *this = (*this) + other;}
  inline Matrix& operator -= (const Matrix& other) {return *this = (*this) - other;}
  inline Matrix& operator *= (const Matrix& other) {return *this = (*this) * other;}
  inline bool operator == (const Matrix& other) {return M == other.M;}
  inline bool operator != (const Matrix& other) {return M != other.M;}
};

void solve() {
  ll n; cin >> n;
  cout << Matrix<mint>({{1, 1}, {1, 0}}).pow(n)[0][1] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}