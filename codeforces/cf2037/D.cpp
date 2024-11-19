#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

pii hurdle[MX], pu[MX];

void solve() {
  int n, m, L; cin >> n >> m >> L;
  rep(i, 1, n) cin >> hurdle[i].st >> hurdle[i].nd;
  rep(i, 1, m) cin >> pu[i].st >> pu[i].nd;
  int idx = 0, use = 0, cur = 0;
  pq<int> pq;
  rep(i, 1, n) {
    while (idx <= m && pu[idx].st <= hurdle[i].st) pq.push(pu[idx++].nd);
    while (cur <= hurdle[i].nd - hurdle[i].st) {
      if (pq.empty()) return void(cout << -1 << nl);
      cur += pq.top(); pq.pop();
      use++;
    }
  }
  cout << use << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}