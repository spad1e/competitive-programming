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
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

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
const int MX = 2e5 + 10;

ll a[MX], b[MX], ans[MX];
bool choose[MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n+m+1) cin >> a[i];
  rep(i, 1, n+m+1) cin >> b[i];

  int cntn = 0, cntm = 0;
  rep(i, 1, n+m) {
    if (cntn == n) break;
    if (cntm == m) break;
    cntn += (a[i] > b[i]);
    cntm += (b[i] > a[i]);
  }
  if (cntm == m) {
    swap(n, m); 
    rep(i, 1, n+m+1) swap(a[i], b[i]);
  }
  ll cnt = 0, sum = 0, tmp = 0;
  rep(i, 1, n+m+1) {
    if (cnt == n && tmp == 0 && a[i] > b[i]) tmp = a[i] - b[i];
    
    if (cnt == n) sum += b[i];
    else if (a[i] > b[i]) choose[i] = 1, cnt++, sum += a[i];
    else sum += b[i];
  }
  if (!tmp) tmp = a[n+m+1] - b[n+m+1];
  rep(i, 1, n+m+1) cout << (choose[i] ? sum-a[i]+tmp : sum-b[i]) << " "; cout << nl;
  rep(i, 1, n+m+1) choose[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}