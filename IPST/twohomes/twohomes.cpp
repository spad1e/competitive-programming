#include <bits/stdc++.h>
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#include "twohomes.h"
//#include "grader.cpp"
using namespace std;

const int maxN = 1010;

int rep[maxN];
vector<pii> adj[maxN], ord;
vector<int> base;

int f(int i) {
    return (rep[i] == i ? i : rep[i] = f(rep[i]));
}

void dfs(int i, int prt) {
    for (auto [j, tmp] : adj[i]) {
        if (j != prt) {
            ord.pb({tmp, j});
            dfs(j, i);
        }
    }
}

pii find_homes(int N, int M, vector<vector<int>> R) {
    int cnt = 0;
    for (int i = 0; i < N; ++i) rep[i] = i;
    for (int i = 0; i < M; ++i) {
        int u = R[i][0], v = R[i][1];
        if (f(u) == f(v)) base.pb(i);
        else {
            adj[u].pb({v, i});
            adj[v].pb({u, i});
            rep[f(u)] = rep[f(v)];
        }
    }
    dfs(0, -1);
    int l = 0, r = ord.size();
    while (l < r) {
        vector<int> check = base;
        int mid = (l+r)/2;
        for (int i = mid+1; i < ord.size(); ++i) check.pb(ord[i].st);
        if (is_reachable(check)) r = mid;
        else l = mid+1;
        cnt++;
    }
    int s = ord[l].nd;
    ord.clear();
    dfs(s, -1);
    l = 0, r = ord.size();
    while (l < r) {
        vector<int> check = base;
        int mid = (l+r)/2;
        for (int i = mid+1; i < ord.size(); ++i) check.pb(ord[i].st);
        if (is_reachable(check)) r = mid;
        else l = mid+1;
        cnt++;
    }
    int t = ord[l].nd;
    assert(cnt <= 20);
    return {s, t};
}
