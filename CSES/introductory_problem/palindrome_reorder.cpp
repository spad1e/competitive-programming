#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int cnt[26];

void solve() {
  string s; cin >> s;
  for (auto x : s) cnt[x-'A']++;
  int odd = -1; string ans;
  rep(i, 26) {
    if (cnt[i] % 2 && odd != -1) return void (cout << "NO SOLUTION" << nl);
    if (cnt[i] % 2) odd = i;
    ans += string(cnt[i]/2, (char)(i+'A'));
  }
  cout << ans;
  if (odd != -1) cout << (char)(odd+'A');
  reverse(all(ans));
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}