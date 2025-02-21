#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e3 + 3;

vi v[MX];
int p[MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, n) p[i] = -1, v[i].clear();
  rep(i, n) rep(j, m) {
    int x; cin >> x;
    if (x < n) p[x] = i;
    v[i].pb(-x);
  }
  rep(i, n) sort(all(v[i]));
  rep(k, n*m) {
    int i = k % n;
    if (p[i] == -1) return void(cout << -1 << nl);
    if (v[p[i]].back() != -k) return void(cout << -1 << nl);
    v[p[i]].pop_back();
  }
  rep(i, n) cout << p[i]+1 << " \n"[i==n-1];
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}