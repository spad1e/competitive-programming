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

template<int BIT>
struct BinaryTrie {
  struct Node {
    array<int, 2> ch;
    int cnt;
    Node() : ch{-1, -1}, cnt(0) {}
  };
  vector<Node> t;
  BinaryTrie() : t{Node()} {}
  int new_node() {
    t.emplace_back(Node());
    return t.size()-1;
  }
  int size() { return t[0].cnt; }
  bool empty() { return size()==0; }
  void insert(ll val, int k=1) {
    int cur = 0;
    t[cur].cnt += k;
    for (int i = BIT-1; i >= 0; --i) {
      int b = val>>i & 1;
      if (t[cur].ch[b] == -1) t[cur].ch[b] = new_node();
      cur = t[cur].ch[b];
      t[cur].cnt += k;
    }
  }
  void erase(ll val, int k=1) {
    if (count(val) < k) return;
    int cur = 0;
    t[cur].cnt -= k;
    for (int i = BIT-1; i >= 0; --i) {
      int b = val>>i & 1;
      cur = t[cur].ch[b];
      t[cur].cnt -= k;
    }
  }
  ll get_max(ll val) {
    if (empty()) return LLONG_MIN;
    int cur = 0, ans = 0;
    for (int i = BIT-1; i >= 0; --i) {
      int b = val>>i & 1;
      if (t[cur].ch[!b] != -1 && t[t[cur].ch[!b]].cnt > 0) cur = t[cur].ch[!b], ans <<= 1, ans++;
      else cur = t[cur].ch[b], ans <<= 1;
    }
    return ans;
  }
  ll get_min(ll val) {
    if (empty()) return LLONG_MAX;
    int cur = 0, ans = 0;
    for (int i = BIT-1; i >= 0; --i) {
      int b = val>>i & 1;
      if (t[cur].ch[b] != -1 && t[t[cur].ch[b]].cnt > 0) cur = t[cur].ch[b], ans <<= 1;
      else cur = t[cur].ch[!b], ans <<= 1, ans++;
    }
    return ans;
  }
  int count(ll val) {
    int cur = 0;
    for (int i = BIT-1; i >= 0; --i) {
      int b = val>>i & 1;
      if (t[cur].ch[b] == -1) return false;
      cur = t[cur].ch[b];
    }
    return t[cur].cnt;
  }
};

int a[MX];

void solve() {
  int n; ll k; cin >> n >> k;
  rep(i, 1, n) cin >> a[i];
  
  function<ll(int)> check = [&](int x) {
    ll cnt = 0;
    BinaryTrie<30> t;
    int l = 1;
    rep(r, 1, n) {
      while (t.size()>0 && t.get_min(a[r]) <= x) t.erase(a[l++]);
      cnt += l-1;
      t.ins(a[r]);
    }
    return cnt;
  };

  ll l=0, r=(1<<30)-1;
  while (l<r) {
    ll mid = (l+r)>>1;
    if (check(mid) >= k) r = mid;
    else l = mid+1; 
  }
  cout << l << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}