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
const int MX = 2e3 + 10;

vector<int> adj[MX];
string ex[MX];
int cnt;
map<char, int> prio = {{'+', -4}, {'*', -3}, {'^', -2}, {'(', -1}, {')', -1}};

void build_tree(int i) {
  string &s = ex[i];
  int ss = sz(ex[i]);
  if (ss == 1) return void(adj[i].pb(i));
  bool inparen = 0;
  int minprio = 0, cur = 0;
  rep(i, ss) {
    if (s[i] == ')') inparen = 0;
    if (s[i] == '(') inparen = 1;
    if (!inparen) ckmin(minprio, prio[s[i]]);
  }
  if (minprio == -1) {
    string t = s.substr(1, ss-2);
    ex[++cnt] = t;
    adj[i].pb(cnt);
  }
  else {
    rep(j, ss) {
      if (s[j] == ')') inparen = 0;
      if (s[j] == '(') inparen = 1;
      if (!inparen && prio[s[j]] == minprio) {
        string t = s.substr(cur, j-cur);
        cur = j+1;
        ex[++cnt] = t;
        adj[i].pb(cnt);
      }
    }
    string t = s.substr(cur, ss-cur);
    ex[++cnt] = t;
    adj[i].pb(cnt);
  }
  for (auto &j : adj[i]) build_tree(j);
}

string print_ans(vector<int> &v, int i, int j) {
  if (i == sz(v)) {
    cout << "p";
    return j==-1 ? "null" : ex[j];
  }
  else {
    cout << "op(" << v[sz(v)-i-1]+1 << ",";
    string s;
    if (j == -1) s = print_ans(v, i+1, -1);
    else s = print_ans(v, i+1, sz(adj[j]) > v[i] ? adj[j][v[i]] : -1); 
    cout << ")";
    return s;
  }
}

void solve() {
  string s; cin >> s;
  ex[0] = s;
  build_tree(0);
  int n; cin >> n;
  while (n--) {
    vector<int> ask;
    while (1) {
      int c; cin >> c;
      if (c==0) break;
      else ask.pb(c-1);
    }
    string ans = print_ans(ask, 0, 0);
    cout << "=" << ans << nl;
  }
}  

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}