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
const int MX = 2e3 + 10;

const int H = 1e7 + 10;
pii hash_table[H];
bool occupied[H];

void add(ll x, ll y) {
  ll num = ((797*x + 617*y)%H + H) % H;
  while(occupied[num]) num = (num+1) % H;
  occupied[num] = 1;
  hash_table[num].st = x;
  hash_table[num].nd = y;
}

bool query(ll x, ll y) {
  ll num = ((797*x + 617*y)%H + H) % H;
  while (occupied[num]) {
    if (hash_table[num].st == x && 
        hash_table[num].nd == y) return 1;
    num = (num+1) % H;
  }
  return 0;
}

pii earth[MX], water[MX], wind[MX], fire[MX];

void solve() {
  int tx, ty; cin >> tx >> ty;
  int n; cin >> n;
  rep(i, 1, n) cin >> earth[i].st >> earth[i].nd;
  rep(i, 1, n) cin >> water[i].st >> water[i].nd;
  rep(i, 1, n) cin >> wind[i].st >> wind[i].nd;
  rep(i, 1, n) cin >> fire[i].st >> fire[i].nd;

  rep(i, 1, n) rep(j, 1, n) add(earth[i].st + fire[j].st, earth[i].nd + fire[j].nd);
  rep(i, 1, n) rep(j, 1, n) {
    if (query(tx - water[i].st - wind[j].st, ty - water[i].nd - wind[j].nd)) {
      rep(k, 1, n) rep(l, 1, n) {
        if (water[i].st + wind[j].st + earth[k].st + fire[l].st == tx &&
          water[i].nd + wind[j].nd + earth[k].nd + fire[l].nd == ty) {
          cout << earth[k].st << " " << earth[k].nd << nl;
          cout << water[i].st << " " << water[i].nd << nl;
          cout << wind[j].st << " " << wind[j].nd << nl;
          cout << fire[l].st << " " << fire[l].nd << nl;
          return;
        }
      }
    }
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}