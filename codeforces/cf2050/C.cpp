#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  string s; cin >> s;
  int cnt = 0, cnt2 = 0, cnt3 = 0;
  for (auto x : s) {
    if (x == '2') cnt2++;
    else if (x == '3') cnt3++;
    else cnt += x-'0';
  }
  rep(i, 0, cnt2) {
    int cur = cnt + 2*i + 4*(cnt2-i);
    if (cur % 9 == 0) return void(cout << "YES" << nl);
    if (cur % 9 == 6 && cnt3 > 0) return void(cout << "YES" << nl);
    if (cur % 9 == 3 && cnt3 > 1) return void(cout << "YES" << nl);
  }
  cout << "NO" << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}