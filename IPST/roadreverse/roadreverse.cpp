#include <bits/stdc++.h>
#include "roadreverse.h"
//#include "grader.cpp"
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
using namespace std;

const int NN = 1e5;
const int KK = 10;

int dp[NN][KK], cnt;
bool mark[NN];
vector<int> adj[NN], rev[NN];
map<int, pii> mp;
stack<int> topo;

void dfs(int i) {
    if (mark[i]) return;
    mark[i] = 1;
    for (auto j : rev[i]) {
        dfs(j);
    }
    topo.push(i);
}

int count_roads(int N, int M, int K, vector<vector<int>> S, vector<pair<int,int>> R) {
    for (int i = 0; i < S.size(); ++i) {
        for (int j = 0; j < S[i].size(); ++j) {
            mp[S[i][j]] = {i, j};
            adj[(j==0?0:S[i][j-1])].pb(S[i][j]);
            rev[S[i][j]].pb((j==0?0:S[i][j-1]));
        }
    }
    for (auto [i, j] : R) {
        adj[i].pb(j); rev[j].pb(i);
    }

    for (int i = 0; i < N; ++i) {
        if (!mark[i]) dfs(i);
    }

    for (int i = 0; i < NN; ++i)
        for (int j = 0; j < KK; ++j)
            dp[i][j] = INT_MAX;

    while (!topo.empty()) {
        int i = topo.top(); topo.pop();
        for (auto j : adj[i]) {
            for (auto l : adj[i]) {
                if (l == j) continue;
                for (int k = 0; k < K; ++k) {
                    dp[i][k] = min(dp[i][k], dp[l][k]);
                    if (mp[l].st == k) dp[i][k] = min(dp[i][k], mp[l].nd);
                }
            }
            cnt += (dp[i][mp[j].st] > mp[j].nd);
            for (int k = 0; k < K; ++k) dp[i][k] = INT_MAX;
        }
        for (auto j : adj[i]) {
            for (int k = 0; k < K; ++k) {
                dp[i][k] = min(dp[i][k], dp[j][k]);
                if (mp[j].st == k) dp[i][k] = min(dp[i][k], mp[j].nd);
            }
        }
    }

    return cnt;
}

