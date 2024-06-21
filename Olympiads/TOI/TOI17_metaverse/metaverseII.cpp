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
typedef tuple<int, int, int, int> t4;
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
const int MX = 2e4 + 10;

template<class Node>
struct SegTree {
	int n;
	vector<Node> t;
	SegTree(){};
	SegTree(int n, Node v=Node()) {init(n, v);}
	template<class T>
	SegTree(const vector<T> &a) {init(a);}
	void init(int n, Node v=Node()) {init(vector<Node>(n, v));}
	template<class T>
	void init(const vector<T> &a) {
		n=sz(a);
		t.assign(4<<31-__builtin_clz(n),Node());
		function<void(int, int, int)> build=[&](int l, int r, int i) {
			if (l==r) return void(t[i]=a[l-1]);
			int m = (l+r)/2;
			build(l, m, 2*i);
			build(m+1, r, 2*i+1);
			pull(i);
		};
		build(1, n, 1);
	}
	void pull(int i) {t[i] = t[2*i] + t[2*i+1];}
	void modify(int l, int r, int i, int x, const Node &v) {
		if (x<l || x>r) return;
		if (l==r) return void(t[i]=v);
		int m = (l+r)/2;
		if (x<=m) modify(l, m, 2*i, x, v);
		else modify(m+1, r, 2*i+1, x, v);
		pull(i);
	}
	void modify(int x, const Node &v) {modify(1, n, 1, x, v);}
	template<class T>
	void update(int l, int r, int i, int x, const T &v) {
		if (x<l || x>r) return;
		if (l==r) return void(t[i].apply(l, r, v));
		int m = (l+r)/2;
		if (x<=m) update(l, m, 2*i, x, v);
		else update(m+1, r, 2*i+1, x, v);
		pull(i);
	}
	template<class T>
	void update(int x, const T &v) {update(1, n, 1, x, v);}
	Node query(int l, int r, int i, int x, int y) {
		if (y<l || x>r) return Node();
		if (x<=l && r<=y) return t[i];
		int m = (l+r)/2;
		return query(l, m, 2*i, x, y) + query(m+1, r, 2*i+1, x,y);
	}
	Node query(int x, int y) {return query(1, n, 1, x, y);}
	template<class F>
	int findfirst(int l, int r, int i, int x, int y, const F &f) {
		if (y<l||r<x||!(f(t[i]))) return -1;
		if (l==r) return l;
		int m = (l+r)/2;
		int ret = findfirst(l, m, 2*i, x, y, f);
		if (ret == -1) ret = findfirst(m+1, r, 2*i+1, x, y, f);
		return ret;
	}
	template<class F>
	int findfirst(int x, int y, const F &f) {return findfirst(1, n, 1, x, y, f);}
	template<class F>
	int findlast(int l, int r, int i, int x, int y, const F &f) {
		if (y<l||r<x||!(f(t[i]))) return -1;
		if (l==r) return l;
		int m = (l+r)/2;
		int ret = findlast(m+1, r, 2*i+1, x, y, f);
		if (ret == -1) ret = findlast(l, m, 2*i, x, y, f);
		return ret;
	}
	template<class F>
	int findlast(int x, int y, const F &f) {return findlast(1, n, 1, x, y, f);}
};

struct Node {
	int val;
	Node(int x=INT_MAX):val(x){}
	void apply(int l, int r, int x) {val = min(val, x);}
	friend Node operator+(const Node &lhs, const Node &rhs) {
		return Node(min(lhs.val, rhs.val));
	}
};

const int P = 20;

pii s[MX], e[MX];
int dis[MX][P], cnt;
map<int, int> mpy;

int dist(pii a, pii b) {
  return abs(a.st-b.st)+abs(a.nd-b.nd);
}

void solve() {
  int n, m, k, p; cin >> n >> m >> k >> p;
  rep(i, 1, k) cin >> s[i].st >> s[i].nd >> e[i].st >> e[i].nd;
  s[0] = e[0] = {1, 1}; s[k+1] = e[k+1] = {n, m};
	vector<t4> v, r;
	rep(i, 0, k+1) {
		v.pb({s[i].st, 1, s[i].nd, i}); v.pb({e[i].st, 0, e[i].nd, i});
		r.pb({s[i].st, 0, s[i].nd, i}); r.pb({e[i].st, 1, e[i].nd, i});
		mpy[s[i].nd] = mpy[e[i].nd] = 0;
	}
	for (auto &[x, y] : mpy) y = ++cnt;
	sort(all(v)); 
	sort(all(r)); reverse(all(r));

	rep(i, 0, k+1) rep(j, 0, p) dis[i][j] = INF;
	rep(i, 0, k+1) dis[i][0] = dist(s[0], s[i]);
	SegTree<Node> t[2];
	rep(l, 1, p) {
		rep(z, 2) t[z].init(cnt, Node(INF));
		for (auto [x, type, y, j] : v) {	
			if (!type) {
				t[0].update(mpy[y], dis[j][l-1] - x - y);
				t[1].update(mpy[y], dis[j][l-1] - x + y);
			}
			else {
				ckmin(dis[j][l], t[0].query(1, mpy[y]).val + x + y);
				ckmin(dis[j][l], t[1].query(mpy[y], cnt).val + x - y);
			}
		}
		rep(z, 2) t[z].init(cnt, Node(INF));
		for (auto [x, type, y, j] : r) {
			if (type) {
				t[0].update(mpy[y], dis[j][l-1] + x - y);
				t[1].update(mpy[y], dis[j][l-1] + x + y);
			}
			else {
				ckmin(dis[j][l], t[0].query(1, mpy[y]).val - x + y);
				ckmin(dis[j][l], t[1].query(mpy[y], cnt).val - x - y);
			}
		}
	}
	repd(i, 0, p-1) if (dis[k+1][i] != dis[k+1][i+1]) return void(cout << dis[k+1][i+1] << " " << i+1 << nl);
}  

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}