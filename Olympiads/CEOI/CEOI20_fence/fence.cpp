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

ll h[MX], w[MX], sz;
pll stk[MX]; //h, w

mint calc(mint H, mint W) {
  return (H*(H+1)/2)*(W*(W+1)/2);
}
mint calc(mint H, mint Hp, mint W) {
  return H*Hp*(W*(W+1)/2);
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> h[i];
  for (int i = 1; i <= n; ++i) cin >> w[i];
  mint ans = 0;
  stk[++sz] = {h[1], w[1]};
  for (int i = 2; i <= n; ++i) {
    ll curw = 0;
    while(sz && stk[sz].st >= h[i]) {
      auto [H, W] = stk[sz--];
      ll dif = (H-max(h[i], stk[sz].st));
      curw += W;
      ans += calc(dif, curw) + calc(dif, H-dif, curw);
    }
    curw += w[i];
    stk[++sz] = {h[i], curw}; 
  }
  ll curw = 0;
  while(sz) {
    auto [H, W] = stk[sz--];
    ll dif = (H-stk[sz].st);
    curw += W;
    ans += calc(dif, curw) + calc(dif, H-dif, curw);
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

