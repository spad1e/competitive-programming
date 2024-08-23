#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

ll binpow(ll a, ll b) {
  ll res = 1;
  for (;b;b>>=1,a=a*a%MOD) if(b&1) res=res*a%MOD;
  return res;
}

void solve() {
  ll n, k; cin >> n >> k;
  ll m = n/3;
  if (n%3==0) {
    cout << k*binpow(k-1, m-1)%MOD << nl;
  }
  else if (n%3==1) {
    cout << k*binpow(k-1, m)%MOD*(m+1)%MOD << nl;
  }
  else {
    cout << ( (m+1)*(m+2)/2%MOD*k%MOD*binpow(k-1, m+1)%MOD + k*binpow(k-1, m)%MOD*(m+1)%MOD) % MOD << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}