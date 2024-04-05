#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll ll>
#define st first
#define nd second
#define pb push_back
using namespace std;

const int maxN = 2e5 + 10;

int fw[maxN], a[maxN];

void update(int i, int v, int n) {
    for (; i <= n; i += i&-i) fw[i] += v;
}

int query(int i) {
    int ret = 0;
    for (; i > 0; i -= i&-i) ret += fw[i];
    return ret;
}

int srchR(int x, int n) {
    int l = x, r = n+1;
    while (l < r) {
        int md = (l+r)/2;
        if (query(md) - query(x-1) > 0) r = md;
        else l = md+1;
    }
    return l;
}

int srchL(int x, int n) {
    int l = 0, r = x;
    while (l < r) {
        int md = (l+r+1)/2;
        if (query(x) - query(md-1) > 0) l = md;
        else r = md-1;
    }
    return l;
}

vector<int> idx[maxN];

void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n+10; ++i) idx[i].clear();
    for (int i = 0; i <= n+10; ++i) fw[i] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        idx[a[i]].pb(i);
    }
    a[n+1] = 0;
    if (idx[0].size() != 1) {
        cout << "No" << '\n';
        return;
    }
    update(idx[0][0], 1, n);
    for (int i = 1; i <= n; ++i) {
        for (auto j : idx[i]) {
            if (a[srchL(j, n)] != i-1 && a[srchR(j, n)] != i-1) {
                cout << "No" << '\n';
                return;
            }
        }
        for (auto j : idx[i]) {
            update(j, 1, n);
        }
    }
    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
}