#include<bits/stdc++.h>
#include "medal.h"
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define st first
#define nd second
#define pb push_back
using namespace std;

const int N = 1e5 + 10;
const int L = log2(N) + 10;

vector<int> adj[N];
ll w[N], up[N][L], mx[N][L][11], dis[N], lvl[N];
ll dp[N][11];

void dfs(int a, int prt) {
    dis[a] = dis[prt] + w[a];
    lvl[a] = lvl[prt] + 1;
    up[a][0] = prt;
    for (int j = 1; j <= 10; ++j) mx[a][0][j] = dp[a][j];
    for (int i = 1; i < L; ++i) {
        up[a][i] = up[up[a][i-1]][i-1];
        for (int j = 1; j <= 10; ++j) {
            mx[a][i][j] = max(mx[a][i-1][j], mx[up[a][i-1]][i-1][j]);
        }
    }
    for (auto b : adj[a]) {
        if (b != prt) dfs(b, a);
    }
}

pll lca(int a, int b, int x) {
    if (lvl[a] < lvl[b]) swap(a, b);
    int j = lvl[a]-lvl[b];
    ll ret = 0;
    for (int i = 0; i < L; ++i) {
        if (j & (1<<i)) {
            ret = max(ret, mx[a][i][x]);
            a = up[a][i];
        }
    }

    if (a==b) return {a, max(ret, dp[a][x])};
    for (int i = L-1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            ret = max(ret, max(mx[b][i][x], mx[a][i][x]));
            a = up[a][i];
            b = up[b][i];
        }
    }
    return {up[a][0], max(max(ret, dp[up[a][0]][x]), max(dp[a][x], dp[b][x]))};
}

void initialize(int N, int Q, vector<int> W, vector<pii> R) {
    for (int i = 0; i < N; ++i) w[i+1] = W[i];
    for (int i = 0; i < N-1; ++i) {
        int a = R[i].st+1, b = R[i].nd+1;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int k = 1; k <= 10; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (auto j : adj[i]) {
                dp[i][k] = max(dp[i][k], dp[j][k-1] + w[j] + w[i]);
            }
        }
    }
    dfs(1, 1);
    return;
}

long long query(int A, int B, int X)
{
    A++, B++;
    auto [C, l] = lca(A, B, X/2);
    return dis[A] + dis[B] - 2*dis[C] + w[C] + l;
}
