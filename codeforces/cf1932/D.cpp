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
const int MX = 1e5 + 3;

void solve() {
  int n; cin >> n; 
  char T; cin >> T;
  vi d, c, s, h, t;
  rep(i, 1, 2*n) {
    string S; cin >> S;
    if (S[1] == T) t.pb(S[0]-'0');
    else if (S[1] == 'S') s.pb(S[0]-'0');
    else if (S[1] == 'D') d.pb(S[0]-'0');
    else if (S[1] == 'H') h.pb(S[0]-'0');
    else if (S[1] == 'C') c.pb(S[0]-'0');
  }
  sort(all(s)); sort(all(c)); sort(all(d)); sort(all(h)); sort(all(t));
  vector<string> ans;
  int idx = 0;
  rep(i, 0, sz(s)-1, 2) {
    if (i == sz(s)-1 && idx < sz(t)) ans.pb(to_string(s[i]) + "S " + to_string(t[idx++]) + T);
    else if (i == sz(s)-1) {cout << "IMPOSSIBLE" << nl; return;}
    else ans.pb(to_string(s[i]) + "S " + to_string(s[i+1]) + "S");
  }
  rep(i, 0, sz(d)-1, 2) {
    if (i == sz(d)-1 && idx < sz(t)) ans.pb(to_string(d[i]) + "D " + to_string(t[idx++]) + T);
    else if (i == sz(d)-1) {cout << "IMPOSSIBLE" << nl; return;}
    else ans.pb(to_string(d[i]) + "D " + to_string(d[i+1]) + "D");
  }
  rep(i, 0, sz(c)-1, 2) {
    if (i == sz(c)-1 && idx < sz(t)) ans.pb(to_string(c[i]) + "C " + to_string(t[idx++]) + T);
    else if (i == sz(c)-1) {cout << "IMPOSSIBLE" << nl; return;}
    else ans.pb(to_string(c[i]) + "C " + to_string(c[i+1]) + "C");
  }
  rep(i, 0, sz(h)-1, 2) {
    if (i == sz(h)-1 && idx < sz(t)) ans.pb(to_string(h[i]) + "H " + to_string(t[idx++]) + T);
    else if (i == sz(h)-1) {cout << "IMPOSSIBLE" << nl; return;}
    else ans.pb(to_string(h[i]) + "H " + to_string(h[i+1]) + "H");
  }
  rep(i, idx, sz(t)-1, 2) {
    ans.pb(to_string(t[i]) + T + " " + to_string(t[i+1]) + T);
  }
  trav(i, ans) cout << i << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}