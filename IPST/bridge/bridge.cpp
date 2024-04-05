#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define st first
#define nd second
#include "bridge.h"
//#include "grader.cpp"
using namespace std;

const int maxN = 1<<17;
pll seg[maxN<<1];
ll qs[maxN], qss[maxN], cnt;
ll dpL[maxN], dpR[maxN];
map<int, int> mp, rv;

ll f(pll p, ll x) {
    return p.st*rv[x] + p.nd;
}

void clr(int l, int r, int idx) {
    seg[idx] = {0, 1e18};
    if (l==r) return;
    int mid = (l+r)/2;
    clr(l, mid, 2*idx);
    clr(mid+1, r, 2*idx+1);
}

void update(int l, int r, pll p, int idx) {
    int m = (l+r)/2;
    bool lft = f(seg[idx], l) < f(p, l);
    bool mid = f(seg[idx], m) < f(p, m);
    if (!mid) swap(seg[idx], p);
    if (l == r) return;
    if (lft != mid) update(l, m, p, 2*idx);
    else update(m+1, r, p, 2*idx+1);
}

ll query(int l, int r, ll x, int idx) {
    if (l==r) return f(seg[idx], x);
    int mid = (l+r)/2;
    if (x <= mid) return min(query(l, mid, x, 2*idx), f(seg[idx], x));
    else return min(query(mid+1, r, x, 2*idx+1), f(seg[idx], x));
}

ll destroy_bridge(int N, vector<int> W) {
    for (int i = 1; i <= N; ++i) qs[i] = qs[i-1] + W[i-1], qss[i] = qss[i-1] + W[i-1]*W[i-1];
    for (int i = 1; i <= N; ++i) mp[qs[i]] = 0;
    for (auto [i, j] : mp) {
        mp[i] = ++cnt;
        rv[cnt] = i;
    }
    clr(1, cnt, 1);
    for (int i = 1; i <= N; ++i) {
        dpL[i] = query(1, cnt, mp[qs[i]], 1) + qs[i]*qs[i] - qss[i];
        if (i > 1) dpL[i] = min(dpL[i], 2LL*W[i-1]*W[i-2]);
        update(1, cnt, {-2*qs[i-1], qs[i-1]*qs[i-1] + qss[i-1]}, 1);
    }
    for (int i = 2; i <= N; ++i) dpL[i] = min(dpL[i], dpL[i-1]);

    clr(1, cnt, 1);
    for (int i = N; i >= 1; --i) {
        dpR[i] = query(1, cnt, mp[qs[i-1]], 1) + qs[i-1]*qs[i-1] + qss[i-1];
        if (i < N) dpR[i] = min(dpR[i], 2LL*W[i-1]*W[i]);
        update(1, cnt, {-2*qs[i], qs[i]*qs[i] - qss[i]}, 1);
    }
    for (int i = N-1; i >= 1; --i) dpR[i] = min(dpR[i], dpR[i+1]);

    ll ans = 1e18;
    for (int i = 2; i < N; ++i) ans = min(ans, dpL[i-1] + dpR[i+1]);
    return ans/2;
}
