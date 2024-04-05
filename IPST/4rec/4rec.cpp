#include <bits/stdc++.h>
#include <vector>
//#include "grader.cpp"
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;

const int maxN = 5e5 + 10;

int fw[maxN][2], mpY[maxN];
vector<int> X, Y, inX[maxN];

void update(int i, int val, int j) {for (; i < maxN; i += i&-i) fw[i][j] += val;}
int query(int i, int j) {int ret = 0; for (; i > 0; i -= i&-i) ret += fw[i][j]; return ret;}

int srch(int l, int r, int target, int f, int s) {
    while (l < r) {
        int mid = (l+r+1)/2;
        if (query(mid-1, f) - (query(sz(Y), s) - query(mid-1, s)) >= target) r = mid-1;
        else l = mid;
    }
    return l;
}

ll find_rec(vector<vector<int>> Point, int P, int Q) {
    int N = Point.size();
    for (int i = 0; i < N; ++i) X.pb(Point[i][0]), inX[Point[i][0]].pb(Point[i][1]);
    for (int i = 0; i < N; ++i) Y.pb(Point[i][1]);
    vector<int>::iterator it;
    sort(all(X)); it = unique(all(X)); X.resize(it - X.begin());
    sort(all(Y)); it = unique(all(Y)); Y.resize(it - Y.begin());
    for (int i = 0; i < sz(Y); ++i) mpY[Y[i]] = i+1;
    for (int i = 0; i < N; ++i) update(mpY[Point[i][1]], 1, 1);
    ll ans = 0;
    for (int i = 0; i <= sz(X); ++i) {
        int L1 = srch(0, sz(Y)+1, -P, 1, 0);
        int R1 = srch(0, sz(Y)+1, P+1, 1, 0);
        int L2 = srch(0, sz(Y)+1, -Q, 0, 1);
        int R2 = srch(0, sz(Y)+1, Q+1, 0, 1);
        if (L2 < L1) swap(L1, L2), swap(R1, R2);
        if (L2 < R1) ans += min(R1, R2) - max(L1, L2);
        if (i < sz(X)) for (auto j : inX[X[i]]) update(mpY[j], -1, 1), update(mpY[j], 1, 0);
    }
    return ans;
}
