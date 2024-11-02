#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  ll l, r, i, k; cin >> l >> r >> i >> k;
  auto computeXor = [&](ll x) {
    if (x == -1) return 0ll;
    if (x%4 == 0) return x;
    if (x%4 == 1) return 1ll;
    if (x%4 == 2) return x+1;
    if (x%4 == 3) return 0ll;
    return 0ll;
  };
  auto computeInteresting = [&](ll x) {
    ll ans = computeXor((x>>i)-1)<<i;
    if (((x>>i)-1) % 2 == 0) ans ^= k;
    ll clear = (1ll<<i)-1;
    return ans ^ ((x&clear) >= k ? x ^ (x&clear) ^ k : 0);
  };
  cout << (computeXor(r) ^ computeXor(l-1) ^ computeInteresting(l-1) ^ computeInteresting(r)) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}