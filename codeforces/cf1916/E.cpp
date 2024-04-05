#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define rep0(a) for (ll i = 1; i <= a; ++i)
#define rep1(i, a) for (ll i = 1; i <= a; ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b, c) for (ll i = a; i <= b; i+=c) 
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define repd0(a) for (ll i = a; i >= 1; --i)
#define repd1(i, a) for (ll i = a; i >= 1; --i)
#define repd2(i, a, b) for (ll i = b; i >= a; --i)
#define repd3(i, a, b, c) for (ll i = b; i >= a; i-=c)
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
const char nl = '\n';
const int MX = 3e5 + 3;

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
    t.assign((4<<(31-__builtin_clz(n)))+1, Node());
    lz.assign((4<<(31-__builtin_clz(n)))+1, Tag());
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
    lz[i] = Tag();
  }
  void modify(int l, int r, int i, int x, const Node &v) {
    if (x<l||x>r) return;
    if (l==r) return void(t[i]=v);
    int m=(l+r)/2;
    push(l,r,i);
    modify(l,m,2*i,x,v);
    modify(m+1,r,2*i+1,x,v);
    pull(i);
  }
  void modify(int x, const Node &v) { modify(1,n,1,x,v); }
  void update(int l, int r, int x, int y, int i, const Tag &v) {
    if (y<l||x>r) return;
    if (x<=l&&r<=y) return apply(l, r, i, v);
    int m=(l+r)/2;
    push(l, r, i);
    update(l, m, x, y, 2*i, v);
    update(m+1, r, x, y, 2*i+1, v);
    pull(i);
  }
  void update(int x, int y, const Tag &v) { update(1, n, x, y, 1, v); }
  void update(int x, const Tag &v) { update(1, n, x, x, 1, v); }
  Node query(int l, int r, int x, int y, int i) {
    if (y<l || x>r) return Node();
    if (x<=l&&r<=y) return t[i];
    int m=(l+r)/2;
    push(l, r, i);
    return query(l, m, x, y, 2*i)+query(m+1, r, x, y, 2*i+1);
  }
  Node query(int x, int y) { return query(1, n, x, y, 1); }
  Node query(int x) { return query(1, n, x, x, 1); }
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
    return Node(max(lhs.val, rhs.val)); 
  }
};

vi adj[MX], down[MX];
int in[MX], out[MX], up[MX], a[MX], cnt; ll ans = 1;

LazySegTree<Node, Tag> t;

void dfs(int i) {
  in[i] = ++cnt;
  if (up[a[i]] != 0) down[up[a[i]]].pb(i); 
  int tmp = up[a[i]];
  up[a[i]] = i;
  trav(j, adj[i]) dfs(j);  
  out[i] = cnt; 
  up[a[i]] = tmp;
}

void dfs2(int i) {
  trav(j, adj[i]) dfs2(j);
  t.update(in[i], out[i], Tag(1));
  trav(j, down[i]) t.update(in[j], out[j], Tag(-1));
  vll v;
  trav(j, adj[i]) {
    v.pb(t.query(in[j], out[j]).val);
  }
  ll mx1 = 1, mx2 = 1; 
  trav(j, v) {
    if (j > mx1) mx2 = mx1, mx1 = j;
    else if (j > mx2) mx2 = j;
  }
  ckmax(ans, mx1*mx2);
}

void solve() {
  int n; cin >> n;
  t.init(n);
  rep(i, 2, n) {
    int p; cin >> p;
    adj[p].pb(i);
  }
  rep(i, 1, n) cin >> a[i];
  dfs(1);
  dfs2(1);
  cout << ans << nl;
  rep(i, 1, n) adj[i].clear(), down[i].clear(), up[i] = in[i] = out[i] = 0;
  cnt = 0, ans = 1;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}


