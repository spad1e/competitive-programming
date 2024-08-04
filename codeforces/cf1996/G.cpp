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
const int MX = 1<<18;

struct Node {
  ll val, cnt;
  Node(ll _val=LINF, ll _cnt=1) : val(_val), cnt(_cnt) {}
} t[MX<<1];

int a[MX], lz[MX];

void push(int i) {
  t[2*i].val += lz[i];
  lz[2*i] += lz[i];
  t[2*i+1].val += lz[i];
  lz[2*i+1] += lz[i];
  lz[i] = 0;
}

Node merge(Node a, Node b) {
  if (a.val < b.val) return a;
  if (a.val > b.val) return b;
  return Node(a.val, a.cnt + b.cnt);
}

void build(int l, int r, int i) {
  lz[i] = 0;
  if (l==r) return void(t[i] = Node(a[l]));
  int mid = (l+r)>>1;
  build(l, mid, 2*i);
  build(mid+1, r, 2*i+1);
  t[i] = merge(t[2*i], t[2*i+1]);
}

Node query(int l, int r, int a, int b, int i) {
  if (a>r||b<l) return Node();
  if (a<=l&&r<=b) return t[i];
  int mid = (l+r)>>1;
  push(i);
  return merge(query(l, mid, a, b, 2*i), 
               query(mid+1, r, a, b, 2*i+1));
}

void update(int l, int r, int a, int b, int i, int val) {
  if (a>r||b<l) return;
  if (a<=l&&r<=b) {
    lz[i] += val;
    t[i].val += val;
    return;
  }
  int mid = (l+r)>>1;
  push(i);
  update(l, mid, a, b, 2*i, val);
  update(mid+1, r, a, b, 2*i+1, val);
  t[i] = merge(t[2*i], t[2*i+1]);
}

vi idxl[MX], idxr[MX];

void solve() {
  int n, m; cin >> n >> m;
  build(1, n, 1);
  rep(i, 1, n) idxl[i].clear(), idxr[i].clear();
  rep(i, 1, m) {
    int l, r; cin >> l >> r;
    idxl[l].pb(r); idxr[r].pb(l);
    update(1, n, l, r-1, 1, 1);
  }
  ll ans = t[1].cnt;
  rep(i, 1, n) {
    for (auto x : idxl[i]) {
      update(1, n, i, x-1, 1, -1);
      update(1, n, 1, i-1, 1, 1);
      update(1, n, x, n, 1, 1);
    }
    for (auto x : idxr[i]) {
      update(1, n, 1, x-1, 1, -1);
      update(1, n, i, n, 1, -1);
      update(1, n, x, i-1, 1, 1);
    }
    ckmax(ans, t[1].cnt);
  }
  cout << (n-ans) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}