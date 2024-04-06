/*
Extended Euclidean Algorithm
Modified from : https://github.com/gean-dev/icpc-book/blob/main/content/number-theory/ExtendedEuclid.hpp
Verification :
  https://codeforces.com/contest/1932/problem/G
*/
#pragma once
#include "../template/header.hpp"

pair<ll,ll> euclid(ll a,ll b){
  ll x=1,y=0,x1=0,y1=1;
  while(b!=0){
    ll q=a/b;
    x-=q*x1;
    y-=q*y1;
    a-=q*b;
    swap(x,x1);
    swap(y,y1);
    swap(a,b);
  }
  return {x,y};
}