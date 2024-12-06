#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  string s; cin >> s;
  int n = s.size();
  function<void(int)> recur = [&](int i) {
    if (i==0) return;
    if (s[i]-1 > s[i-1]) {
      swap(--s[i], s[i-1]);
      recur(i-1);
    } 
  };
  rep(i, 1, n-1) recur(i); 
  cout << s << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}