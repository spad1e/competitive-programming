#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll ll>
#define st first
#define nd second
#define pb push_back
using namespace std;

const int maxN = 5e3 + 3;
const int M = 998244353;

ll fac[maxN], inv[maxN], a[maxN], cnt[2*maxN];

ll power(ll a, ll b) {
    if (b == 0) return 1;
    ll ret = power(a, b/2);
    if (b%2==0) return ret*ret%M;
    else return ret*ret%M*a%M;
}

void initfac() {
    fac[0] = 1;
    for (int i = 1; i < maxN; ++i) fac[i] = (i*fac[i-1]) % M;
    inv[maxN-1] = power(fac[maxN-1], M-2);
    for (int i = maxN-2; i >= 0; --i) inv[i] = (i+1)*inv[i+1] % M;
}

ll C(ll n, ll r) {
    if (r > n) return 0;
    if (n < 0) return 0;
    if (r < 0) return 0;
    return fac[n]*inv[n-r]%M*inv[r]%M;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int mx = max(0LL, a[n]), mn = min(0LL, a[1]);
    for (int i = -n; i <= n; ++i) cnt[maxN+i] = 0;
    for (int i = n; i >= 1; --i) cnt[maxN+a[i]]++;
    cnt[maxN]++;
    ll ans = 0;
    for (int i = mn; i <= mx; ++i) {
        ll total = 1, cur = cnt[maxN+mx] + (mx>0) - (mx==i);
        for (int j = mx-1; j >= mn; --j) {
            int x = cnt[maxN+j]-cur, y = cur;
            total = (total * C(x+y-1, y-1)) % M;
            cur = cnt[maxN+j]-cur + (j>i) + (j>0);
        }
        if (cur != 0) total = 0;
        ans = (ans + total) % M;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t = 1;
    cin >> t;
    initfac();
    while (t--) solve();
}