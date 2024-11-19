#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX], cnt[MX];

void solve() {
  int n; cin >> n;
  int score = 0;
  rep(i, 1, n) {
    cin >> a[i];
    cnt[a[i]]++;
    if (cnt[a[i]]%2 == 0) score++;
  }
  cout << score << nl;
  rep(i, 1, n) cnt[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}