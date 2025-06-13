#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], idx[MX];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) cin >> a[i], idx[a[i]] = i;
  while (q--) {
    int l, r, k; cin >> l >> r >> k;
    if (idx[k] < l || idx[k] > r) { cout << -1 << " "; continue; }
    int le = k-1, ge = n-k, move_l = 0, move_r = 0;
    vector<int> v;
    while (l < r) {
      int mid = (l+r)>>1;
      if (idx[k] == mid) break;
      if (mid < idx[k]) {
        if (a[mid] < k) le--;
        else v.pb(a[mid]), move_r++;
        l = mid+1;
      }
      else {
        if (a[mid] > k) ge--;
        else v.pb(a[mid]), move_l++;
        r = mid-1;
      }
    }
    int ans = v.size();
    if (move_l > ge || move_r > le) cout << -1 << " ";
    else {
      for (auto x : v) {
        if (x < k && move_r > 0) move_r--;
        if (x > k && move_l > 0) move_l--; 
      }
      cout << ans + move_l + move_r << " ";
    }
  }
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}