#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define st first
#define nd second
#include "pattern.h"
//#include "grader.cpp"
using namespace std;

const int maxN = 2e5 + 10;
const int MD = 1e9 + 7;
vector<int> adj[maxN];
ll calc1[maxN], calc2[maxN];
ll dp[maxN][7], force[maxN], m, cnt;

ll add(ll a, ll b) {return ((((a%MD)+(b%MD))%MD)+MD)%MD;}
ll mul(ll a, ll b) {return (a%MD*b%MD)%MD;}

ll power(ll a, ll b) {
    if (b==0) return 1;
    ll ret = power(a, b/2);
    return b&1 ? mul(mul(ret, ret), a) : mul(ret, ret);
}

void dfs(int i) {
    if (adj[i].size() == 0) {
        if (force[i]) dp[i][force[i]] = 1, dp[i][6] = 1;
        else {
            for (int j = 1; j <= cnt; ++j) dp[i][j] = 1;
            dp[i][0] = m-cnt;
            dp[i][6] = m;
        }
        return;
    }
    for (auto j : adj[i]) dfs(j);
    for (int k = 0; k <= cnt; ++k) {
        if (force[i] && k != force[i]) continue;
        int now = 0;
        calc1[now++] = 1;
        ll cur = 1;
        for (int idx = 0; idx < adj[i].size(); ++idx) {
            int j = adj[i][idx];
            if (k == 0 && dp[j][k] != 0) cur = mul(cur, add(add(dp[j][6], -dp[j][0]), mul(dp[j][0], mul(m-cnt-1, power(m-cnt, MD-2)))));
            else cur = mul(cur, dp[j][6] - dp[j][k]);
            calc1[now++] = cur;
        }
        calc1[now] = calc1[now-1];
        calc2[now--] = 1;
        cur = 1;
        for (int idx = adj[i].size()-1; idx >= 0; --idx) {
            int j = adj[i][idx];
            cur = mul(cur, dp[j][6]);
            calc2[now--] = cur;
        }
        calc2[now] = calc2[now+1];
        for (int idx = 0; idx < adj[i].size(); ++idx) {
            int j = adj[i][idx];
            dp[i][k] = add(dp[i][k], mul(mul(calc1[idx], calc2[idx+2]), dp[j][k]));
        }
    }
    for (int k = 0; k <= cnt; ++k) dp[i][6] = add(dp[i][6], dp[i][k]);
}

int total_pattern(int N, int M, vector<vector<int>> Path, vector<vector<int>> p) {
    m = M;
    for (int i = 0; i < N-1; ++i) {
        adj[Path[i][0]].pb(Path[i][1]);
    }
    int P = p.size();
    for (int i = 0; i < P; ++i) {
        bool repeat = 0;
        for (int j = 0; j < i; ++j) {
            if (p[i][1] == p[j][1]) repeat = 1;
        }
        if (!repeat) force[p[i][0]] = ++cnt;
        else {
            for (int j = 0; j < i; ++j) {
                if (p[i][1] == p[j][1]) force[p[i][0]] = force[p[j][0]];
            }
        }
    }
    dfs(0);
    return dp[0][6];
}
