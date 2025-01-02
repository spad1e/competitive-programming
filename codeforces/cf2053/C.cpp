#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, k; cin >> n >> k;
  ll cur = 0, val = 0, cnt = 1;
  while (n >= k) {
    if (n&1) cur += val + cnt*(n/2+1);
    val += val + cnt*((n+1)/2);
    cnt *= 2;
    n /= 2; 
  }
  cout << cur << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}