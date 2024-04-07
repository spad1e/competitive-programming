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
const int MX = 3e5 + 3;

template<class T>
struct fenwick {
  int n;
  vector<T> t;
  fenwick (int n=0){init(n);}
  void init(int _n) {
    n=_n;
    t.assign(n+1, T{});
  }
  void update(int x, const T &v) {
    for(int i = x+1; i <= n; i+=i&-i) t[i] = t[i]+v;
  }
  void update(int l, int r, const T &v) {
    update(l, v); update(r+1, -v);
  }
  T query(int x) {
    T res{};
    for (int i = x+1; i > 0; i-=i&-i) res = res+t[i];
    return res;
  }
  T query(int l, int r) {
    return query(r) - query(l-1);
  }
  //find the first index that sums to >= k
  int find(const T &k) {
    int x = 0;
    T cur{};
    for (int i = 1<<(31-__builtin_clz(n)); i > 0; i>>=1)
      if (x+i <= n && cur+t[x+i] < k) x+=i, cur+=t[x];
    return x;
  }
};

template<class Node, class Tag>
struct LazySegTree{
  int n;
  vector<Node> t;
  vector<Tag> lz;
  LazySegTree() {}
  LazySegTree(int n, Node v=Node()) {init(n, v);}
  template<class T>
  LazySegTree(const vector<T> &a) {init(a);}
  void init(int n, Node v=Node()) {init(vector<Node>(n, v));}
  template<class T>
  void init(const vector<T> &a) {
    n=sz(a);
    t.assign(4<<(31-__builtin_clz(n)), Node());
    lz.assign(4<<(31-__builtin_clz(n)), Tag());
    function<void(int, int, int)> build=[&](int l, int r, int i){
      if (l==r) return void(t[i]=a[l-1]);
      int m=(l+r)/2;
      build(l,m,2*i);
      build(m+1,r,2*i+1);
      pull(i);
    };
    build(1,n,1);
  }
  void pull(int i) {
    t[i]=t[2*i]+t[2*i+1];
  }
  void apply(int l,int r,int i,const Tag &v) {
    t[i].apply(l,r,v);
    lz[i].apply(l,r,v);
  }
  void push(int l, int r, int i) {
    int m=(l+r)/2;
    apply(l,m,2*i, lz[i]);
    apply(m+1,r,2*i+1, lz[i]);
    lz[i]=Tag();
  }
  void modify(int l,int r,int x,int i,const Node &v) {
    if (x<l||x>r) return;
    if (l==r) return void(t[i]=v);
    int m=(l+r)/2;
    push(l,r,i);
    modify(l,m,2*i,x,v);
    modify(m+1,r,2*i+1,x,v);
    pull(i);
  }
  void modify(int x,const Node &v){ modify(1,n,x,1,v); }
  void update(int l,int r,int x,int y,int i,const Tag &v) {
    if (y<l||x>r) return;
    if (x<=l&&r<=y) return apply(l, r, i, v);
    int m=(l+r)/2;
    push(l,r,i);
    update(l,m,x,y,2*i,v);
    update(m+1,r,x,y,2*i+1,v);
    pull(i);
  }
  void update(int x,int y,const Tag &v) { update(1,n,x,y,1,v); }
  void update(int x,const Tag &v) { update(1,n,x,x,1,v); }
  Node query(int l,int r,int x,int y,int i) {
    if (y<l||x>r) return Node();
    if (x<=l&&r<=y) return t[i];
    int m=(l+r)/2;
    push(l,r,i);
    return query(l,m,x,y,2*i)+query(m+1,r,x,y,2*i+1);
  }
  Node query(int x,int y){ return query(1,n,x,y,1); }
  Node query(int x){ return query(1,n,x,x,1); }
};
struct Tag{
  ll val;
  Tag(ll _val=0):val(_val){}
  void apply(int l, int r, const Tag &v) { val+=v.val; }
};
struct Node{
  ll val;
  Node(ll _val=0):val(_val){}
  void apply(int l, int r, const Tag &v) { val+=v.val; }
  friend Node operator+(const Node &lhs, const Node &rhs) {
    return Node(min(lhs.val, rhs.val)); 
  }
};


vll _index(MX), ans(MX, -1); vector<tuple<int, ll, ll>> ord[MX];
fenwick<ll> cnt(MX), del(MX);
LazySegTree<Node, Tag> s(MX);

void solve() {
  int n, m, q; cin >> n >> m >> q;
  rep (T, 1, q) {
    int t; cin >> t;
    if (t == 1) {
      ll l, r, c, k; cin >> l >> r >> c >> k;
      ord[l].pb({1, T, k}); ord[r+1].pb({1, T, -k});
      _index[T] = c;
    }
    if (t == 2) {
      ll l, r, k; cin >> l >> r >> k;
      ord[l].pb({2, T, k}); ord[r+1].pb({2, T, -k});
    }
    if (t == 3) {
      ll a, b; cin >> a >> b;
      ord[a].pb({3, T, b});
    }
  }
  rep(i, 1, n) {
    ll d = 0;
    for(auto [op, T, k] : ord[i]) {
      if (op == 1) cnt.update(T, k), s.update(T, q, k);  
      if (op == 2) del.update(T, k), s.update(T, q, -k);
      if (op == 3) {
        int idx = cnt.find(k + del.query(T) + s.query(1, T).val);
        ans[T] = (idx > T ? 0 : _index[idx]);
      }
    }
  }
  trav(a, ans) if (a != -1) cout << a << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}