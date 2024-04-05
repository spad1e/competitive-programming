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
const int MX = 1e3 + 3;

int ans[MX][MX];

void solve() {
  int n, k; cin >> n >> k;
  if (k % 2 == 1) {cout << "No" << nl; return;}
  if (n == 2 && k == 2) {cout << "Yes\n1 0\n0 1" << nl; return;}
  if (k == n*n -2 || k == 2) {cout << "No" << nl; return;}
  if (k%4 == 0) {
    int cnt = 0;
    rep(i, 1, n/2) {
      rep(j, 1, n/2) {
        if (cnt == k) break;
        ans[2*i][2*j] = ans[2*i][2*j-1] = ans[2*i-1][2*j] = ans[2*i-1][2*j-1] = 1; 
        cnt += 4;
      }
    }
  }
  else {
    int cnt = 0;
    rep(i, 1, n/2) {
      rep(j, 1, n/2) {
        if (i<=2&&j<=2) continue;
        if (cnt == k-6) break;
        ans[2*i][2*j] = ans[2*i][2*j-1] = ans[2*i-1][2*j] = ans[2*i-1][2*j-1] = 1; 
        cnt += 4;
      }
    }
    if (cnt+6 != k) ans[1][3] = ans[1][4] = ans[4][3] = ans[4][4] = 1; 
    ans[1][1] = ans[1][2] = ans[2][1] = ans[2][3] = ans[3][2] = ans[3][3] = 1;
  }
  cout << "Yes" << nl;
    rep(i, 1, n) {
      rep(j, 1, n) {
        cout << ans[i][j] << " ";
      }
      cout << nl;
    }
  rep(i, 1, n) rep(j, 1, n) ans[i][j] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}

