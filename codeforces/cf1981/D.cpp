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
const int MX = 1e6 + 10;
const int SQ = 1510;

vi adj[MX];
int deg[MX], cnt, mark[SQ][SQ], prime[MX], mark2[MX];

void dfs(int i, int prt, int n) {
  for (auto j : adj[i]) {
    if (j == prt) continue;
    int ii = min(i, j), jj = max(i, j);
    if (mark[ii][jj]) continue;
    mark[ii][jj] = 1;
    dfs(j, i, n);
  }
  if (cnt++ >= n) return;
  cout << prime[i] << " ";
}

void find_primes() {
  rep(i, 2, MX-1) {
    if (mark2[i]) continue;
    prime[++cnt] = i;
    rep(j, i, MX-1, i) mark2[j] = 1;
  } 
}

void solve() {
  int n, k; cin >> n;
  cnt = 0;
  rep(i, 1, n+1) {
    adj[i].clear(); deg[i] = 0;
    if (i%2==1 && i*(i+1)/2 >= n-1) {k=i; break;}
    else if (i%2==0 && i*i/2 + 1 >= n-1) {k=i; break;}
  }
  rep(i, 1, k) rep(j, i, k) {
    adj[i].pb(j), adj[j].pb(i);
    deg[i]++, deg[j]++;
    mark[i][j] = 0;
  }
  if (k%2 == 0) rep(i, 3, k, 2) mark[i][i+1] = 1;
  dfs(1, 0, n);
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  find_primes();
  while (t--) { solve(); }
  return 0;
}