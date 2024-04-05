#include <bits/stdc++.h>
#define ll long long
#define pll pair<__int128, __int128>
#define st first
#define nd second
#define pb push_back
#include "celeb.h"
//#include "grader.cpp"
using namespace std;

pll intersect(pll a, pll b) {
    return {b.nd-a.nd, a.st-b.st};
}

bool cmp(pll a, pll b) {
    return a.st*b.nd <= a.nd*b.st;
}

vector<ll> max_revenue(int N, int K, vector<ll> X, vector<int> M) {
    vector<ll> rev;
    int j = K-1;
    deque<pll> dq;
    for (int i = N-1; i >= 0; --i) {
        while (dq.size() >= 2 && cmp(intersect(dq[dq.size()-2], {-i, X[i]}), intersect(dq[dq.size()-2], dq.back()))) dq.pop_back();
        dq.push_back({-i, X[i]});
    }
    for (int j = 0; j < K; ++j) {
        while (dq.size() >= 2 && cmp(intersect(dq[1], dq[0]), {M[j], 1})) dq.pop_front();
        auto [m, c] = dq.front();
        rev.pb(m*M[j] + c);
    }
    return rev;
}

