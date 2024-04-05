#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include "underground.h"
//#include "grader.cpp"
#define pii pair<int, int>
#define st first
#define nd second
#define INF INT_MAX
using namespace std;

struct node {
    int dis, i, j;
    bool operator< (const node &o) const {
        return dis<o.dis;
    }
};

const int N = 501;
int Ar[N][N], dp[N][N][16];
int R, C;

void dij(int k) {
    bool vis[N][N];
    priority_queue<node> pq;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            vis[i][j] = 0;
            if (dp[i][j][k] == 1e9) continue;
            if (i<R-1 && dp[i+1][j][k] + Ar[i][j] < dp[i][j][k]) continue;
            if (i>0 && dp[i-1][j][k] + Ar[i][j] < dp[i][j][k]) continue;
            if (j<C-1 && dp[i][j+1][k] + Ar[i][j] < dp[i][j][k]) continue;
            if (j>0 && dp[i][j-1][k] + Ar[i][j] < dp[i][j][k]) continue;
            pq.push({-dp[i][j][k], i, j});
        }
    }

    while (!pq.empty()) {
        int i = pq.top().i;
        int j = pq.top().j;
        pq.pop();
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        if (i<R-1 && dp[i+1][j][k] > dp[i][j][k] + Ar[i+1][j])
            dp[i+1][j][k] = dp[i][j][k] + Ar[i+1][j], pq.push({-dp[i+1][j][k], i+1, j});
        if (i>0 && dp[i-1][j][k] > dp[i][j][k] + Ar[i-1][j])
            dp[i-1][j][k] = dp[i][j][k] + Ar[i-1][j], pq.push({-dp[i-1][j][k], i-1, j});
        if (j<C-1 && dp[i][j+1][k] > dp[i][j][k] + Ar[i][j+1])
            dp[i][j+1][k] = dp[i][j][k] + Ar[i][j+1], pq.push({-dp[i][j+1][k], i, j+1});
        if (j>0 && dp[i][j-1][k] > dp[i][j][k] + Ar[i][j-1])
            dp[i][j-1][k] = dp[i][j][k] + Ar[i][j-1], pq.push({-dp[i][j-1][k], i, j-1});
    }
}

int dig_paths(int R, int C, vector<vector<int>>& a) {
    ::R = R;
    ::C = C;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            Ar[i][j] = a[i][j];
            for (int k = 0; k < 16; ++k) dp[i][j][k] = 1e9;
        }
    }
    dp[0][0][1<<0] = Ar[0][0];
    dp[R-1][0][1<<1] = Ar[R-1][0];
    dp[0][C-1][1<<2] = Ar[0][C-1];
    dp[R-1][C-1][1<<3] = Ar[R-1][C-1];

    for (int k = 1; k < 16; ++k) {
        for (int s = 0; s < 4; ++s) {
            if (!k&(1<<s)) continue;
            for (int i = 0; i < R; ++i)
                for (int j = 0; j < C; ++j)
                    dp[i][j][k] = min(dp[i][j][k], dp[i][j][1<<s] + dp[i][j][k^(1<<s)] - Ar[i][j]);
        }
        dij(k);
    }
    int ans = INT_MAX;
    for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) ans = min(ans, dp[i][j][15]);
    return ans;
}
