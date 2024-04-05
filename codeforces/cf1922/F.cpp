#include <climits>
#include <cwchar>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef vector<vi> vvi;

template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define rep0(a) for (ll i = 1; i <= a; ++i)
#define rep1(i, a) for (ll i = 1; i <= a; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b, c) for (ll i = a; i <= b; i+=c) 
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define repd0(a) for (ll i = a; i >= 1; --i)
#define repd1(i, a) for (ll i = a; i >= 1; --i)
#define repd2(i, a, b) for (ll i = b; i >= a; --i)
#define repd3(i, a, b, c) for (ll i = b; i >= a; i-=c)
#define repd(...) overload4(__VA_ARGS__, repd3, repd2, repd1, repd0)(__VA_ARGS__)
#define trav(a, x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define ins insert

template<typename T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const char nl = '\n';
const int MX = 110;

int dp[MX][MX][MX], a[MX], dp2[MX][MX][MX], mark[MX][MX];

void ck(int l,int r, int k) {
  if (mark[l][r]) return;
  mark[l][r] = 1;
  rep(x, 1, k) {
    if (l==r) dp[l][r][x] = (a[l] != x), dp2[l][r][x] = (a[l] == x);
    else {
      ck(l+1, r, k);
      if (a[l]==x) dp[l][r][x] = dp[l+1][r][x];
      else dp2[l][r][x] = dp2[l+1][r][x];
    }
  } 
  if (l==r) return;
  rep(x, 1, k) {
    if (a[l]==x) continue;
    ckmin(dp[l][r][x], dp2[l][r][x]+1);
    rep(i, l, r-1) {
      ck(l, i, k); ck(i+1, r, k);
      ckmin(dp[l][r][x], dp[l][i][x] + dp[i+1][r][x]);
    }
  }
  rep(x, 1, k) if (x != a[l]) ckmin(dp2[l][r][a[l]], dp[l][r][x]);
  rep(i, l, r-1) ckmin(dp2[l][r][a[l]], dp2[l][i][a[l]] + dp2[i+1][r][a[l]]); 
}

void solve() {
  int n, x; cin >> n >> x;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) rep(j, 1, n) rep(k, 0, x) dp[i][j][k] = dp2[i][j][k] = 1e9, mark[i][j] = 0;
  ck(1, n, x);
  int ans = INT_MAX;
  rep(i, 1, x) ckmin(ans, dp[1][n][i]);
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}

