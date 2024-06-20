/*Note: This problem is probably unsolvable? There are testcases where the official solution will get TLE.

This is probably one of the following testcases.
9 1
000101101100100010000100011100100001000100000111011001100100010110010110
1100010101011011110000010000011101100101000001010010000011111000
10011000000110111011110110011011010101111001001100010
0011110001001111010111100100100000000110000001100010011111000010000110010010010
00101010010101000000000111010011101001001010001011011011111011010010000100000
01100100000101001000001101101001001001000111100
0000100011010000010001101100111111000000010111100001010010
011101001000100111001110010101110
001001

So please do not attempt.
*/
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
const int MX = 20;

string s[MX];
ll m[MX], cur = LLONG_MAX;

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> s[i];
  m[0] = 1; 
  rep(i, 1, n) m[i] = m[i-1]*sz(s[i])/__gcd(m[i-1], (ll)sz(s[i]));

  function<ll(int, ll)> srch = [&](int wheel, ll pos) {
    if (wheel > n) return cur = min(cur, pos);
    for(ll i = pos; i<cur&&i<=m[wheel]; i+=m[wheel-1]) {
      if (s[wheel][i%sz(s[wheel])]-'0' == k) srch(wheel+1, i);
    }
    return cur;
  };

  cout << srch(1, 1) << nl;
}  

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}