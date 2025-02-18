#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  string s; cin >> s;
  int n = s.size(); s = " " + s;

  auto check_palindrome = [&](int l, int r) {
    if (l >= r) return 1;
    int cmp = r;
    rep(i, l, r) if (s[i] != s[cmp--]) return 0;
    return 1;
  };

  auto check = [&](int x) {
    int l = 1, r = n;
    while (l < r && s[l] == s[r]) l++, r--;
    vi cntl(26, 0), cntr(26, 0);
    int cntxl = x, cntxr = x;
    bool okl = 1, okr = 1;
    rep(i, l, min(l+x-1, r)) cntl[s[i] - 'a']++;
    repd(i, l+x, r) {
      if (cntxl > 0 && cntl[s[i] - 'a'] == 0) { okl = 0; break; } 
      else if (cntxl > 0) cntl[s[i] - 'a']--, cntxl--;
      else break;
    }

    rep(i, max(r-x+1, l), r) cntr[s[i] - 'a']++;
    rep(i, l, r-x) {
      if (cntxr > 0 && cntr[s[i] - 'a'] == 0) { okr = 0; break; }
      else if (cntxr > 0) cntr[s[i] - 'a']--, cntxr--;
      else break;
    }

    return (okl || okr) && check_palindrome(l+x, r-x);
  };

  int l = 0, r = n;
  while (l < r) {
    int mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  cout << l << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}