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

ll a[MX], d[MX], nxt[MX], prv[MX], cnt[MX], dead[MX];

void solve() {
  int n; cin >> n;
  a[n+1] = d[n+1] = 0;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> d[i];
  rep(i, 1, n) nxt[i] = i+1, prv[i] = i-1, cnt[i] = 0, dead[i] = 0;
  vi out, ck;
  rep(i, 1, n) ck.pb(i);
  rep(i, 1, n) {
    out.clear();
    trav(j, ck) {
      if (dead[j]) continue;
      if (j < 1 || j > n) continue;
      if (d[j] < a[prv[j]]+a[nxt[j]]) {
        dead[j] = 1;
        cnt[i]++;
        out.pb(j);
      }
    } 
    ck.clear();
    trav(j, out) {
      prv[nxt[j]] = prv[j];
      nxt[prv[j]] = nxt[j];
      ck.pb(prv[j]); ck.pb(nxt[j]);
    }
  }
  rep(i, 1, n) cout << cnt[i] << " ";
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}


