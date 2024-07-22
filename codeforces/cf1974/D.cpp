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

map<char, int> m = {{'N', 0}, {'E', 1}, {'W', 2}, {'S', 3}};

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int cntN = 0, cntS = 0, cntW = 0, cntE = 0;
  queue<int> q[4];
  rep(i, n) {
    q[m[s[i]]].push(i);
  }
  string ans = string(n, 'X');
  rep(i, n) {
    if (ans[i] != 'X') continue;
    int cur = m[s[i]], opp = 3-cur;
    ans[i] = (cur==0||cur==3 ? 'R' : 'H'); q[cur].pop();
    if (sz(q[cur])) ans[q[cur].front()] = (cur==0||cur==3 ? 'H' : 'R'), q[cur].pop();
    else if (sz(q[opp])) ans[q[opp].front()] = (cur==0||cur==3 ? 'R' : 'H'), q[opp].pop();
    else return void(cout << "NO" << nl);
  }
  bool hasH = 0, hasR = 0;
  rep(i, n) hasH |= (ans[i] == 'H'), hasR |= (ans[i] == 'R');
  if (!hasH || !hasR) return void(cout << "NO" << nl);
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}