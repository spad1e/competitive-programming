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
const int MX = 2e5 + 3;

vpii adj[MX];
int state[MX], mask[MX];

template<int BIT, class T = uint32_t, class S = int>
struct BinaryTrie {
  struct Node {
    Node* nxt[2];
    int cnt = 0;
    Node() {
      nxt[0] = nxt[1] = NULL;
      cnt = 0;
    }
  } *root;
  BinaryTrie() { root = new Node(); }
  void insert(T val) {
    Node *cur = root;
    cur -> cnt++;
    for (int i = BIT-1; i >= 0; --i) {
      int b = val>>i & 1;
      if (cur -> nxt[b] == NULL) cur -> nxt[b] = new Node();
      cur = cur -> nxt[b];
      cur -> cnt++;
    }
  }
  void erase(T val) {
    if (!exist(val)) return;
    Node *cur = root;
    cur -> cnt--;
    for (int i = BIT-1; i >= 0; --i) {
      int b = val>>i & 1;
      cur = cur -> nxt[b];
      cur -> cnt--;
    }
  }
  int get_max(T val) {
    Node *cur = root;
    int ans = 0;
    for (int i = BIT-1; i >= 0; --i) {
      int b = val>>i & 1;
      if (cur -> nxt[!b] != nullptr && cur -> nxt[!b] -> cnt > 0) cur = cur -> nxt[!b], ans <<= 1, ans++;
      else if (cur -> nxt[b] != nullptr) cur = cur -> nxt[b], ans <<= 1;
    }
    return ans;
  }
  bool exist(T val) {
    Node *cur = root;
    for (int i = BIT-1; i >= 0; --i) {
      int b = val>>i & 1;
      if (cur -> nxt[b] == nullptr) return false;
      cur = cur -> nxt[b];
    }
    return cur -> cnt > 0;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  BinaryTrie<31> t[2];
  rep(i, 1, n) adj[i].clear();
  rep(i, 1, n-1) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }
  function<void(int, int)> dfs = [&](int u, int p) {
    t[state[u]].ins(mask[u]);
    for (auto [v, w] : adj[u]) {
      if (v==p) continue;
      mask[v] = mask[u]^w;
      state[v] = 1-state[u];
      dfs(v, u);
    }
  };
  dfs(1, 0);
  int x = 0;
  while (q--) {
    char c; int a, b; cin >> c;
    if (c=='^') cin >> a, x ^= a;
    else {
      cin >> a >> b;
      int same = state[a], opp = 1-state[a];
      t[same].erase(mask[a]);
      int mx1 = t[same].get_max(mask[a]^b);
      t[same].ins(mask[a]);
      int mx2 = t[opp].get_max(mask[a]^b^x);
      cout << max(mx1, mx2) << " ";
    }
  }
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}