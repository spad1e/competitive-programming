#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int cnt[26];

bool possible(int c) {
  int mx_occ = 0, cur_occ, freq = 0;
  rep(i, 26) {
    if (ckmax(mx_occ, cnt[i])) cur_occ = i;
    freq += cnt[i];
  }
  if (cur_occ != c) return mx_occ <= (freq + 1)/2;
  return mx_occ <= freq/2;
}

void solve() {
  string s; cin >> s; 
  int n = s.size();
  for (auto x : s) cnt[x-'A']++;
  if (!possible(-1)) return void(cout << -1 << nl);
  string ans;
  while (n--) {
    rep(i, 26) {
      if (!cnt[i] || i==ans.back()-'A') continue;
      cnt[i]--;
      if (possible(i)) {
        ans += (char)('A'+i);
        break;
      }
      else cnt[i]++;
    }
  }
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}