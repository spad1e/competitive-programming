#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], gap[MX];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) cin >> a[i];
  string s; cin >> s; s = " " + s;
  rep(i, 1, n) {
    if (s[i] == 'L') gap[i-1]++;
    else gap[i]++;
  }
  int curmx = 0, cnt = 0, l = 1;
  set<int> nogap, bad;
  rep(i, 1, n) {
    ckmax(curmx, a[i]);
    if (i >= curmx) {
      nogap.emplace(i); 
    }
  }
  rep(i, 1, n-1) if (!nogap.count(i) && gap[i] == 0) bad.emplace(i);
  while (q--) {
    int i; cin >> i;
    s[i] = (s[i] == 'L') ? 'R' : 'L'; 
    if (s[i] == 'L') gap[i-1]++, gap[i]--;
    else gap[i]++, gap[i-1]--;

    if (gap[i] == 0 && !nogap.count(i)) bad.emplace(i);
    if (gap[i-1] == 0 && !nogap.count(i-1)) bad.emplace(i-1);
    if (gap[i] != 0 && bad.count(i)) bad.erase(i);
    if (gap[i-1] != 0 && bad.count(i-1)) bad.erase(i-1);

    cout << (bad.empty() ? "YES" : "NO") << nl;
  }
  rep(i, 0, n+1) gap[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}