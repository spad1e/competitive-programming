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
const int MX = 2e6 + 10;

priority_queue<int> pqL;
priority_queue<int, vector<int>, greater<int>> pqR;
multiset<int> ms;
int x[MX];

void solve() {
  int n, l, a, b; cin >> n >> l >> a >> b;
  rep(i, 1, n) cin >> x[i];
  sort(x+1, x+n+1);
  rep(i, 1, a-1) pqL.push(x[i]);
  rep(i, a, b-1) ms.ins(x[i]);
  rep(i, b, n) pqR.push(x[i]);
  while (l--) {
    int x = *ms.begin();
    int y = pqR.top();
    ms.erase(ms.begin());
    pqR.pop();

    if (ms.empty() || y-x < *ms.begin()) {
      pqL.push(y-x);
      ms.ins(pqL.top());
      pqL.pop();
    }
    else ms.ins(y-x);
    int z = (x+y)/2;
    if (!pqR.empty() || z < pqR.top()) {
      ms.ins(z);
      pqR.push(*(--ms.end()));
      ms.erase(--ms.end());
    }
    else pqR.push(z);
  }
  stack<int> s;
  while (!pqL.empty()) s.push(pqL.top()), pqL.pop();
  while (!s.empty()) cout << s.top() << " ", s.pop();
  for (auto x : ms) cout << x << " ";
  while (!pqR.empty()) cout << pqR.top() << " ", pqR.pop();
  cout << nl;
}  

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}