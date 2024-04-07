/*
Binary Exponentiation
Modified from : https://github.com/gean-dev/icpc-book/blob/main/content/modular-arithmetic/BinPow.hpp
Verification : -
*/
#pragma once
#include "../template/header.hpp"

template<class T>
constexpr T binpow(T a,ll b){
  T res=1;
  for(;b>0;b>>=1,a*=a)if(b&1)res*=a;
  return res;
}