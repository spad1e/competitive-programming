#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;
  
int a[5];

void solve() {
  int n; cin >> n;
  int m = n>>2;
  auto ask = [&](int l, int r) {
    assert(1 <= l && l <= r && r <= n);
    cout << "? " << l << " " << r << nl; cout.flush();
    int x; cin >> x; return x;
  };
  rep(i, 1, 3) a[i] = ask((i-1)*m+1, i*m);
  if (a[1] == a[2] && a[2] == a[3]) a[4] = 1-a[1];
  else if (a[1] == a[2]) a[4] = a[1];
  else if (a[1] == a[3]) a[4] = a[1];
  else a[4] = a[2];
  int cnt0 = 0, cnt1 = 0;
  rep(i, 1, 4) cnt0 += (a[i] == 0), cnt1 += (a[i] == 1);
  if (cnt1 == 3) {
    int region = (a[1] == 1 ? 1 : m+1);
 
    int l = 1, r = m-1;
    while (l < r) {
      int mid = (l+r+1)>>1;
      if (ask(region, region+mid-1)) r=mid-1;
      else l=mid;
    }
    cout << "! " << l+1 << nl; cout.flush();
  }
  else {
    int region;
    rep(i, 1, 4) if (a[i] == 1) region = (i-1)*m+1;
 
    int l = m, r = n-1;
    while (l < r) {
      int mid = (l+r+1)>>1;
      int regionL = region, regionR = region+mid-1;
      if (regionR > n) regionL -= (regionR - n), regionR = n;
      if (ask(regionL, regionR)) l=mid;
      else r=mid-1;
    }
    cout << "! " << l+1 << nl; cout.flush();
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}