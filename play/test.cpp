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

ll A[MX], sum[MX], sum2[MX];

ll calc(int L, int R, int x) {
	return (sum2[x+1] - sum2[R+1] - sum[R+1]*(R-x)) - (sum2[L] - sum2[x+1] - sum[x+1]*(x-L+1));
}

void solve() {
	int N, Q; cin >> N >> Q;
	rep(i, 1, N) cin >> A[i];
	repd(i, 1, N) sum[i] = sum[i+1] + A[i];
	repd(i, 1, N) sum2[i] = sum2[i+1] + sum[i];
	while (Q--) {
		int L, R; cin >> L >> R;
		int l = L, r = R;
		while (l < r) {
			int mid = (l+r+1)/2;
			if (calc(L, R, mid) >= 0) l = mid;
			else r = mid-1;
		}
		cout << min(abs(calc(L, R, l)), abs(calc(L, R, l+1))) << nl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int t = 1;
//	cin >> t;
	while (t--) { solve(); }
	return 0;
}