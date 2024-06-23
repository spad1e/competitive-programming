/*Note: testcase 3 answer is wrong, should be 0 3 instead of 1 2
*/
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
const int MX = 1e5 + 10;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int x[MX], y[MX], hp[MX], itime[MX], stime[MX], qtime[MX], state[MX];
map<pii, int> human;

void solve() {
  int n, T, f, S, q, all = 0, qua = 0;
  cin >> n >> T >> f >> S >> q;
  memset(itime, 0x3f, sizeof(itime)); 
  memset(stime, 0x3f, sizeof(stime));
  memset(qtime, 0x3f, sizeof(qtime));
  pqg<t3> pq;
  rep(i, 1, n) {
    bool v; cin >> x[i] >> y[i] >> hp[i] >> v;
    human[{x[i], y[i]}] = i;
    state[i] = 3;
    if (v) pq.push({0, 2, i}), itime[i] = 0;
  }

  auto update = [&](int xx, int yy, int t) {
    if (!human.count({xx, yy})) return;
    int i = human[{xx, yy}];
    if (state[i] != 3) return;
    vector<int> surround;
    rep(j, 4) {
      int xx = x[i]+dx[j], yy = y[i]+dy[j];
      if (!human.count({xx, yy})) continue;
      int k = human[{xx, yy}];
      if (state[k] == 1) surround.pb(k);
    }
    sort(all(surround), [&](int a, int b) { return qtime[a] < qtime[b]; });
    rep(j, sz(surround)) {
      int idx_q = surround[j], sum = 0, cnt = 0;
      rep(k, j, sz(surround)-1) {
        int idx = surround[k];
        cnt++;
        sum += f-hp[idx]-itime[idx];
      }
      int t_required = max(t, (int)ceil(1.0*(hp[i]-sum)/cnt)); 
      if (t_required < qtime[idx_q]) {
        pq.push({t_required, 2, i});
        ckmin(itime[i], t_required);
        break;
      }
    }
  };

  while (!pq.empty()) {
    auto [t, s, i] = pq.top(); pq.pop();
    if (t > T) break;
    if (s == 2 && t > itime[i]) continue;
    if (s >= state[i]) continue;
    state[i] = s;
    if (s == 2) {
      all++;
      pq.push({stime[i] = t+max(1, hp[i]-S), 1, i});
      pq.push({qtime[i] = t+max(1, hp[i]-q), 0, i});
    }
    if (s == 1) rep(j, 4) update(x[i]+dx[j], y[i]+dy[j], t); 
    if (s == 0) qua++;
  }
  cout << all-qua << nl << qua << nl;
}
 

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}