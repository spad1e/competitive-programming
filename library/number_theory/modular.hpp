/*
Modular Arithmetic (MInt)
Modified from : https://github.com/gean-dev/icpc-book/blob/main/content/number-theory/ModularArithmetic.hpp
Verification : 
  https://codeforces.com/contest/1279/problem/D
  https://codeforces.com/contest/935/problem/D
Not Verified : modmul, modinv, invmod method
Note: might improve integer behavior such as [] operation convertion, boolean conversion, > < operator, etc.
*/
#pragma once
#include "../template/header.hpp"

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
