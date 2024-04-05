#include <unistd.h>
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

#define rep0(a) for (ll i = 0; i < a; ++i)
#define rep1(i, a) for (ll i = 0; i < a; ++i)
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
const int MX = 1e5 + 3;

char c;

vi quicksort(vi v) {
  int sz = sz(v);
  if (sz<=1) return v;
  int p = rng()%sz;
  if (p < 0) p += sz;
  p = v[p];
  c = '0';
  while (c != '=') {
    cout << "? " << p << nl << flush;
    cin >> c;
  }
  vi vl, vr;
  rep(i, 0, sz-1) {
    cout << "? " << v[i] << nl << flush;
    cin >> c;
    if (c == '<') {vl.pb(v[i]); cout << "? " << p << nl << flush; cin >> c;}
    else if (c == '>') {vr.pb(v[i]); cout << "? " << p << nl << flush; cin >> c;}
  }
  int mid = sz(vl)+1;
  vl = quicksort(vl), vr = quicksort(vr);
  vi sorted_v;
  trav(i, vl) sorted_v.pb(i); 
  sorted_v.pb(p);
  trav(i, vr) sorted_v.pb(i);
  return sorted_v;
}

void solve() {
  int n; cin >> n;
  vi v; rep(i, 1, n) v.pb(i);
  vi sorted_v = quicksort(v);
  rep(i, 0, sz(v)-1) {
    v[sorted_v[i]-1] = i+1;
  }
  cout << "!";
  trav(i, v) cout << " " << i;
  cout << nl << flush;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}

