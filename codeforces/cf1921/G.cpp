#include <algorithm>
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

const int M = 1e9 + 7;
const char nl = '\n';
const int MX = 1e5 + 3;

int ans(vvi v, int n, int m, int k) {
  if (m > n) {
    vvi v2(m+3, vi(n+3, 0));
    rep(i, 1, n) rep(j, 1, m) v2[j][i] = v[i][j];
    swap(n, m);
    v = v2;
  }
  n += m;
  vvi dp(n+3, vi(m+3, 0)), dp2(n+3, vi(m+3, 0));
  rep(i, 1, n) rep(j, 1, m) dp2[i][j] = (i > n-m ? 0 : v[i][j]) + dp2[i][j-1] + dp2[i-1][j] - dp2[i-1][j-1];
  rep(i, 1, n) rep(j, 1, m) dp[i][j] = dp[i-1][j-1] + (dp2[i][j] - dp2[i][j-1]);
  int a = 0;
  rep(i, 1, n) rep(j, 1, m) ckmax(a, dp[i][j] - (i>k && j>k ? dp[i-k-1][j-k-1] : 0) - (i>k ? dp2[i-k-1][j] : 0) + (i>k && j>k ? dp2[i-k-1][j-k-1] : 0)); 
  return a;
}

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vvi v(n+2, vi(m+2, 0)), v2(m+2, vi(n+2, 0));
  rep(i, 1, n) rep(j, 1, m) {char c; cin >> c; v[i][j] = (c == '#');}
  rep(i, 1, n) rep(j, 1, m) v2[j][i] = v[i][j]; reverse(all(v2));
  int a = 0;
  ckmax(a, ans(v, n, m, k));
  ckmax(a, ans(v2, m, n, k));
  rep(i, 1, n) reverse(all(v[i]));
  rep(i, 1, m) reverse(all(v2[i]));
  reverse(all(v)); reverse(all(v2));
  ckmax(a, ans(v, n, m, k));
  ckmax(a, ans(v2, m, n, k));
  cout << a << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}


