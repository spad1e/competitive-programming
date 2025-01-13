#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], d[MX], t[MX];

void solve() {
  int n, k, l; cin >> n >> k >> l;
  rep(i, 1, n) cin >> a[i], a[i] *= 2;
  k *= 2, l *= 2;
  t[1] = a[1]; d[1] = k;
  rep(i, 2, n) {
    if (d[i-1] < a[i]-t[i-1]) {
      if (a[i] - t[i-1] <= d[i-1]) {
        t[i] = t[i-1];
        d[i] = d[i-1] + k;
      }
      else {
        t[i] = t[i-1] + (a[i] - t[i-1] - d[i-1]) / 2;
        d[i] = (a[i] - t[i-1] + d[i-1]) / 2 + k;
      }
    }
    else {
      t[i] = t[i-1];
      d[i] = min(a[i] + t[i-1], d[i-1]) + k;
    }
  }
  t[n] += max(0, l - d[n]); 
  cout << t[n] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}