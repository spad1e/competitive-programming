#include<bits/stdc++.h>
#include "train.h"
#define INF 2e9+1
//#include "grader.cpp"
using namespace std;

const int maxN = 1<<18;
int seg[maxN<<1], lz[maxN<<1];

void push(int idx) {
    if (lz[idx] != INF) {
        seg[2*idx] = min(seg[2*idx], lz[idx]);
        seg[2*idx+1] = min(seg[2*idx+1], lz[idx]);
        lz[2*idx] = min(lz[2*idx], lz[idx]);
        lz[2*idx+1] = min(lz[2*idx+1], lz[idx]);
        lz[idx] = INF;
    }
}

void update(int l, int r, int a, int b, int val, int idx) {
    if (a <= l && r <= b) {
        seg[idx] = min(seg[idx], val);
        lz[idx] = min(lz[idx], val);
        return;
    }
    if (l > b || r < a) return;
    if (l!=r) push(idx);
    int mid = (l+r)/2;
    update(l, mid, a, b, val, 2*idx);
    update(mid+1, r, a, b, val, 2*idx+1);
    seg[idx] = min(seg[2*idx], seg[2*idx+1]);
}

int query(int l, int r, int a, int b, int idx) {
    if (a <= l && r <= b) return seg[idx];
    if (l > b || r < a) return INF;
    if (l!=r) push(idx);
    int mid = (l+r)/2;
    return min(query(l, mid, a, b, 2*idx), query(mid+1, r, a, b, 2*idx+1));
}

int find_min_cost(int N, int M, vector<int>& s, vector<int>& t, vector<int>& c) {
    for (int i = 1; i < maxN<<1; ++i) seg[i] = INF, lz[i] = INF;
    update(1, N, 1, 1, 0, 1);
    for (int i = 0; i < M; ++i) {
        int bg = s[i]+1, ed = t[i]+1, co = c[i];
        update(1, N, bg, ed, query(1, N, bg, bg, 1)+co, 1);
    }
    int ret = query(1, N, N, N, 1);
    return (ret == INF ? -1 : ret);
}
