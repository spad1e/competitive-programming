#include<bits/stdc++.h>
#include "goatforget.h"
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define st first
#define nd second
#define pb push_back
#define INF INT_MAX
using namespace std;

const int N = 510;
int adj[N][N];
bool vis[N];

void srch(int i, int l, int r) {
    if (l > r) return;
    int mid = (l+r)/2;
    int ret = talk_tae(mid);
    int dis = abs(mid-ret);
    talk_tae(i);
    adj[i][ret] = 1;
    adj[ret][i] = 1;
    if (ret < mid) {
        for (int j = ret+1; j < mid+dis; ++j) {
            adj[i][j] = -1;
            adj[j][i] = -1;
        }
        srch(i, l, ret-1);
        srch(i, mid+dis, r);
    }
    if (ret > mid) {
        for (int j = max(0, mid-dis); j < ret; ++j) {
            adj[i][j] = -1;
            adj[j][i] = -1;
        }
        srch(i, l, mid-dis-1);
        srch(i, ret+1, r);
    }
    if (ret == mid) {
        srch(i, l, ret-1);
        srch(i, ret+1, r);
    }
}

void dfs(int i, int n) {
    vis[i] = 1;
    int l = -1;
    adj[i][n] = -1;
    for (int j = 0; j <= n; ++j) {
        if (adj[i][j] == 0 && l == -1) l = j;
        if (adj[i][j] != 0 && l != -1) {
            srch(i, l, j-1);
            l = -1;
        }
    }

    for (int j = 0; j < n; ++j) {
        if (vis[j]) continue;
        if (adj[i][j] == 1) {
            talk_tae(j);
            dfs(j, n);
            talk_tae(i);
        }
    }
}

vector<vector<int>> recover_map(int n, int m, int q) {
    dfs(0, n);
    for (int i = 0; i < n; ++i) adj[i][i] = -1;
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (adj[i][j] == 1) v.pb({i, j});
        }
    }

    return v;
}
