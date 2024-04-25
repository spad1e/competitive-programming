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

template<typename T> using pq = priority_queue<T>;
template<typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;

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
const int MX = 5e3 + 3;

vi adj[MX];
int dis[MX];

int check(int i, int n) {
  queue<int> q;
  q.push(i);
  int ret = 0;
  dis[i] = 1;
  while (!q.empty()) {
    int a = q.front(); q.pop();
    ret += dis[a];
    for (auto b : adj[a]) {
      if (!dis[b]) {
        dis[b] = dis[a] + 1; 
        q.push(b);
      }
    }
  }
  bool valid = 1;
  for (int i = 1; i <= n; ++i) if (dis[i] == 0) valid = 0;
  return (valid ? ret : 2e9);
}

void solve() {
  int n; cin >> n;
  for (int i = 1 ; i <= n; ++i) {
    int k, u; cin >> k;
    for (int j = 1; j <= k; ++j) {
      cin >> u; adj[u].pb(i);  
    }
  }
  int ans = 2e9;
  for (int i = 1; i <= n; ++i) {
    memset(dis, 0, sizeof(dis));
    ckmin(ans, check(i, n));
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}

