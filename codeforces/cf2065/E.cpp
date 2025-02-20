#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  bool sw = 0;
  if (n > m) swap(n, m), sw = 1;
  if (k > m) return void(cout << -1 << nl);
  string ans = string(k, sw?'0':'1');
  int prv = k; m-=k;
  for (int i = 1; prv > 0; ++i) {
    int l = min(prv, i%2?n:m);
    ans += string(l, i%2==sw?'1':'0');
    (i%2?n:m) -= l;
    prv = l;
  }
  cout << (n==0&&m==0 ? ans : "-1") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}