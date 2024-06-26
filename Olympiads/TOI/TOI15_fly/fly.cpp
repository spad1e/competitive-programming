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
const int MX = 2e3 + 10;

pii intv[MX][2*MX], open_range[MX][2*MX]; //row, time

void solve() {
  int R, C; cin >> R >> C;
  rep(t, 0, 2*C-1) open_range[0][t] = open_range[R+1][t] = {1, C-1};
  rep(i, 1, R) {
    int l, r; char dirl, dirr; cin >> l >> dirl >> r >> dirr;
    if (l+1 <= r-1) open_range[i][0] = {l+1, r-1};
    else open_range[i][0] = {-1, -1};
    rep(t, 1, 2*C-1) {
      if (l+1 == r && dirl == 'R' && dirr == 'L') swap(dirl, dirr); //not move
      else { //move
        if (l == r && dirl == 'R' && dirr == 'L') swap(dirl, dirr);
        if (l == 0 && dirl == 'L') dirl = 'R';
        if (r == C && dirr == 'R') dirr = 'L';

        l += (dirl == 'L' ? -1 : 1);
        r += (dirr == 'L' ? -1 : 1);
      }
      if (l+1 <= r-1) open_range[i][t] = {l+1, r-1};
      else open_range[i][t] = {-1, -1};
    }
  }  

  queue<pii> q; q.push({0, 0});
  rep(i, 0, R+1) rep(j, 0, 2*C-1) intv[i][j] = {-1, -1};
  intv[0][0] = {1, C-1};
  while (!q.empty()) {
    auto [t, cur_r] = q.front(); q.pop();
    if (cur_r == R+1) return void(cout << t << nl);
    int new_t = t % (2*C);
    int nxt = (new_t+1) % (2*C);

    pii cur_int = intv[cur_r][new_t];
    pii nxt_int = open_range[cur_r][nxt];

    //stay
    if (open_range[cur_r][nxt].st != -1) {
      int nl = max(cur_int.st, nxt_int.st), nr = min(cur_int.nd, nxt_int.nd);
      if (nl <= nr) {
        pii rt_int = intv[cur_r][nxt];
        int ul = (rt_int.st == -1 ? nl : min(rt_int.st, nl));
        int ur = (rt_int.nd == -1 ? nr : max(rt_int.nd, nr));         
        if (ul != rt_int.st || ur != rt_int.nd) {
          intv[cur_r][nxt] = {ul, ur};
          q.push({t+1, cur_r});
        }
      }
    }

    //move
    nxt_int = open_range[cur_r+1][nxt];
    if (open_range[cur_r][t].st != -1) {
      int nl = max(cur_int.st, nxt_int.st), nr = min(cur_int.nd, nxt_int.nd);
      if (nl <= nr) {
        pii rt_int = intv[cur_r+1][nxt];
        int ul = min(rt_int.st, nl); if (ul == -1) ul = nl;
        int ur = max(rt_int.nd, nr); if (ur == -1) ur = nr;         
        if (ul != rt_int.st || ur != rt_int.nd) {
          intv[cur_r+1][nxt] = {ul, ur};
          q.push({t+1, cur_r+1});
        }
      }
    }
  }
}  

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
//  cin >> t;
  while (t--) { solve(); }
  return 0;
}