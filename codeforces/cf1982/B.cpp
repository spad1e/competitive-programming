#include "header.hpp"

void solve() {
  int x, y, k; cin >> x >> y >> k;
  int div = 1;
  while (div < x+k) div *= y;
  while (div > 0) {
    
    div /= y;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}