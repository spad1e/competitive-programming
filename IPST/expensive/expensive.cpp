#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#include "expensive.h"
//#include "grader.cpp"
using namespace std;

const int N = 1e6 + 10;
const int L = 2020;

int deg[N];
int mem[N];
vector<pair<int, pii>> adj[N], adj2[N];
vector<int> v;
int cnt = 0;

void construct(int i, int bgn, int prt, int top, int cura, int curb) {
    if (deg[i] != 2 && i != bgn) {
        adj2[i].pb({top, {cura, curb}});
        adj2[top].pb({i, {cura, curb}});
        top = i;
        cura = curb = 0;
    }
    for (auto [j, tmp] : adj[i]) {
        auto [ca, cb] = tmp;
        if (j == prt) continue;
        construct(j, bgn, i, top, cura+ca, curb+cb);
    }
}

void dfs(int i, int bgn, int prt, int cura, int curb) {
    if (deg[i] == 1 && i != bgn) {
        if (mem[cura] == -1) v.pb(cura);
        mem[cura] = max(mem[cura], curb);
        return;
    }
    for (auto [j, tmp] : adj2[i]) {
        auto [ca, cb] = tmp;
        if (j != prt) dfs(j, bgn, i, cura+ca, curb+cb);
    }
}

void initialize(int N, int Q, vector<pii> R, vector<int> C) {
    int root = 0;
    for (int i = 0; i < N; ++i) mem[i] = -1;
    for (int i = 0; i < N-1; ++i) {
        adj[R[i].st].pb({R[i].nd, {C[i]-1, 2-C[i]}});
        adj[R[i].nd].pb({R[i].st, {C[i]-1, 2-C[i]}});
        deg[R[i].st]++;
        deg[R[i].nd]++;
    }
    for (int i = 0; i < N; ++i) {
        if (deg[i] == 1) root = i;
    }
    construct(root, root, -1, root, 0, 0);
    for (int i = 0; i < N; ++i) {
        if (deg[i] == 1) dfs(i, i, -1, 0, 0);
    }
}

ll most_expensive(int a, int b) {
    ll mx = 0;
    for (auto i : v) {
        mx = max(mx, (ll)a*mem[i] + (ll)b*i);
    }
    return mx;
}

/*
10 2
0 1 2
1 2 1
2 4 1
2 3 2
1 6 1
6 7 2
7 8 2
5 1 1
5 9 1
1 1
5 1
*/
