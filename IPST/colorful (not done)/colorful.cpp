#include <bits/stdc++.h>
//#include "colorful.h"
#include "grader.cpp"
#define pb push_back
#define st first
#define nd second
#define ll long long
#define pii pair<int, int>
using namespace std;

const int N = 5e4 + 10;
const int K = 405;
vector<int> adj[N];
pii nxt[N][K], ans[N][K];
vector<int> primes;
bool mark[2500];
int marknode[N][K];

void init_machine(int N, int M, int K, int Q, vector<int> x, vector<int> y){
    for (int i = 0; i < M; ++i) {
        adj[x[i]].pb(y[i]);
        adj[y[i]].pb(x[i]);
    }

    for (int i = 2; i < 2500; ++i) {
        if (!mark[i]) primes.pb(i);
        for (int j = i; j < 2500; j += i) mark[j] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < K; ++j) {
            int mn = INT_MAX, node = INT_MAX;
            for (auto k : adj[i]) {
                if (k % primes[j] <= mn) {
                    if (k % primes[i] == mn) node = min(node, k);
                    else node = k;
                    mn = k % primes[j];
                }
            }
            if (node == INT_MAX) nxt[i][j] = {i, (j+1)%K};
            else nxt[i][j] = {node, (j+1)%K};
        }
    }

    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (ans[i][j].st == -1) dfs(i, j);
        }
    }
}

int send_ball(int c, int s, ll t){

    return s;
}

