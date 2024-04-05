#include <bits/stdc++.h>
#include "updown.h"
//#include "grader.cpp"
#define pii pair<int, int>
#define st first
#define nd second
using namespace std;

const int N = 1e6 + 10;
pii rep[N][2]; //0 = down state, 1 = up state
int sz[N][2];
map<pair<pii, pii>, int> mp;

pii f(int i, int s) {
    if (rep[i][s] == make_pair(i, s)) return {i, s};
    else return rep[i][s] = f(rep[i][s].st, rep[i][s].nd);
}

vector<int> updown(int N, int M, vector<int> U, vector<int> V) {
    for (int i = 0; i < N; ++i) sz[i][0] = sz[i][1] = 1;
    for (int i = 0; i < N; ++i) rep[i][0] = {i, 0}, rep[i][1] = {i, 1};
    for (int i = 0; i < M; ++i) {
        if (U[i] > V[i]) swap(U[i], V[i]);
        if (f(V[i], 1) == f(U[i], 0)) continue;
        sz[f(V[i], 1).st][f(V[i], 1).nd] += sz[f(U[i], 0).st][f(U[i], 0).nd];
        rep[f(U[i], 0).st][f(U[i], 0).nd] = rep[f(V[i], 1).st][f(V[i], 1).nd];
    }
    for (int i = 0; i < N; ++i) {
        pii A = f(i, 0);
        pii B = f(i, 1);
        mp[{min(A, B), max(A, B)}]++;
    }
    vector<int> ans(N, 0);
    for (int i = 0; i < N; ++i) {
        pii A = f(i, 0);
        pii B = f(i, 1);
        if (A != B) ans[i] = sz[A.st][A.nd]+sz[B.st][B.nd]-mp[{min(A, B), max(A, B)}]-mp[{A, A}]-mp[{B, B}]-1;
        else ans[i] = sz[f(i, 0).st][f(i, 0).nd]-mp[{min(A, B), max(A, B)}]-1;
    }
    return ans;
}

/*
5 5
2 1
1 0
0 4
4 3
3 2
*/
