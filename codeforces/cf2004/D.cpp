#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

string s[MX];

char c[4] = {'R', 'G', 'B', 'Y'};
map<char, int> cL[MX], cR[MX];

void solve() {
  int n, q; cin >> n >> q;
  map<char, int> m;
  rep(i, 1, n) cin >> s[i], cL[i].clear(), cR[i].clear();
  rep(i, 1, n) {
    rep(j, 4) {
      cL[i][c[j]] = max(cL[m[s[i][0]]][c[j]], cL[m[s[i][1]]][c[j]]);
    }
    cL[i][s[i][0]] = cL[i][s[i][1]] = i;
    m[s[i][0]] = m[s[i][1]] = i;
  }  
  m.clear();
  rep(j, 4) m[c[j]] = cR[n+1][c[j]] = n+1;
  repd(i, 1, n) {
    rep(j, 4) {
      cR[i][c[j]] = min(cR[m[s[i][0]]][c[j]], cR[m[s[i][1]]][c[j]]);
    }
    cR[i][s[i][0]] = cR[i][s[i][1]] = i;
    m[s[i][0]] = m[s[i][1]] = i;
  }  

  while (q--) {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    int ans = INF;
    rep(i, 2) {
      if (cR[x][s[y][i]] != n+1) ckmin(ans, 2*cR[x][s[y][i]] - x - y);
      if (cL[x][s[y][i]] != 0) ckmin(ans, x + y - 2*cL[x][s[y][i]]);
    }
    cout << (ans == INF ? -1 : max(ans, y-x)) << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}