#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  string s; cin >> s;
  int n = s.size(); s = " " + s + s.back();
  int a, b, ab, ba; cin >> a >> b >> ab >> ba;
  pqg<pii> pqAB, pqBA;
  int i = 1;
  while (i <= n) {
    int srt = i;
    while (i <= n && s[i] != s[i+1]) i++;
    int l = i - srt + 1;
    if (s[srt] == 'A') pqAB.push({l%2, l});
    if (s[srt] == 'B') pqBA.push({l%2, l});
    i++;
  }
  while (!pqAB.empty() && ab > 0) {
    auto [r, x] = pqAB.top(); pqAB.pop();
    if (x > 1) {
      ab--; if (x > 2) pqAB.push({r, x-2});
    }
    else a--; 
  }
  while (!pqBA.empty() && ba > 0) {
    auto [r, x] = pqBA.top(); pqBA.pop();
    if (x > 1) {
      ba--; if (x > 2) pqBA.push({r, x-2});
    }
    else b--; 
  }
  
  //use the remaining ab and ba
  if (ba > 0) {
    while (!pqAB.empty()) {
      auto [r, x] = pqAB.top(); pqAB.pop();
      a--; if (x > 1) pqBA.push({1-r, x-1});
    }
    while (!pqBA.empty() && ba > 0) {
      auto [r, x] = pqBA.top(); pqBA.pop();
      if (x > 1) {
        ba--; if (x > 2) pqBA.push({r, x-2});
      }
      else b--; 
    }
  }
  if (ab > 0) {
    while (!pqBA.empty()) {
      auto [r, x] = pqBA.top(); pqBA.pop();
      b--; if (x > 1) pqAB.push({1-r, x-1});
    }
    while (!pqAB.empty() && ab > 0) {
      auto [r, x] = pqAB.top(); pqAB.pop();
      if (x > 1) {
        ab--; if (x > 2) pqAB.push({r, x-2});
      }
      else a--; 
    }
  }

  while (!pqAB.empty()) {
    auto [r, x] = pqAB.top(); pqAB.pop();
    a -= (x+1)/2; b -= x/2;
  }
  while (!pqBA.empty()) {
    auto [r, x] = pqBA.top(); pqBA.pop();
    a -= x/2; b -= (x+1)/2;
  }
  cout << (a >= 0 && b >= 0 ? "YES" : "NO") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}