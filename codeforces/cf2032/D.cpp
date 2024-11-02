#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int p[MX];

void solve() {
  int n; cin >> n;
  int query_time = 0;

  auto ask = [&](int u, int v) {
    assert(++query_time <= 2*n-6);
    cout << "? " << u << " " << v << nl;
    cout.flush();
    int x; cin >> x;
    return x;
  };

  queue<int> q; 
  int i = 2;
  for (; i < n; ++i) {
    if (ask(1, i)) q.push(i), p[i] = 0;
    else { 
      q.push(i), p[i++] = 1; 
      break; 
    }
  }
  for (; i < n; ++i) {
    while (ask(q.front(), i)) q.pop();
    int x = q.front(); q.pop(); q.push(i);
    p[i] = x;
  }

  cout << "! ";
  rep(i, 1, n-1) cout << p[i] << " ";
  cout << nl; cout.flush();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}