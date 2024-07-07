#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
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
typedef tuple<int, int, int> t3;
typedef tuple<int, int, int, int> t4;
typedef tuple<int, int, int, int, int> t5;
typedef tuple<ll, ll, ll> tll3;
typedef tuple<ll, ll, ll, ll> tll4;
typedef tuple<ll, ll, ll, ll, ll> tll5;

template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define rep0(a) for (int i = 0; i < a; ++i)
#define rep1(i, a) for (int i = 0; i < a; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define rep3(i, a, b, c) for (int i = a; i <= b; i+=c) 
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define repd0(a) for (int i = a; i >= 1; --i)
#define repd1(i, a) for (int i = a; i >= 1; --i)
#define repd2(i, a, b) for (int i = b; i >= a; --i)
#define repd3(i, a, b, c) for (int i = b; i >= a; i-=c)
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
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int n, m, s[MX], f[MX], dp[MX][2], from[MX][2];
string ans;

bool check(int x) {
  int a, b, c;
  a = b = c = dp[0][0] = dp[0][1] = 1;
  rep(i, 1, n) {
    while (a <= m && f[a] <= s[i]) a++;
    while (b <= m && f[b] <= s[i]+x) b++;
    while (c <= m && f[c] <= s[i-1]+x) c++;
    dp[i][0] = dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
    from[i][0] = from[i][1] = (dp[i-1][0] < dp[i-1][1]);
    if (f[dp[i-1][0]] >= s[i]-x && ckmax(dp[i][0], a)) from[i][0] = 0;
    if (f[dp[i-1][1]] >= s[i]-x && ckmax(dp[i][0], max(a, c))) from[i][0] = 1;
    if (f[dp[i-1][0]] >= s[i] && ckmax(dp[i][1], b)) from[i][1] = 0;
    if (f[dp[i-1][1]] >= s[i] && ckmax(dp[i][1], b)) from[i][1] = 1;
  }
  return max(dp[n][0], dp[n][1])>m;
}

void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> s[i];
  rep(i, 1, m) cin >> f[i];
  s[0] = -INF;
  ans = string(n+1, ' ');
  int l = 0, r = 1e9+1;
  while (l < r) {
    int mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  if (l > 1e9) cout << -1 << nl;
  else {
    check(l);
    int cur = (dp[n][0] < dp[n][1]);
    repd(i, 1, n) ans[i] = (cur ? 'R' : 'L'), cur = from[i][cur]; 
    cout << l << nl << ans.substr(1, n) << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}