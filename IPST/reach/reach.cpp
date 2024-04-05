#include <bits/stdc++.h>
#include "reach.h"
//#include "grader.cpp"
using namespace std;

const int maxN = 1<<17;

int seg[maxN<<1];

void update(int l, int r, int x, int val, int idx) {
    if (l==r) {
        seg[idx] = min(seg[idx], val);
        return;
    }
    int mid = (l+r)/2;
    if (x <= mid) update(l, mid, x, val, 2*idx);
    else update(mid+1, r, x, val, 2*idx+1);
    seg[idx] = min(seg[2*idx], seg[2*idx+1]);
}

int query(int l, int r, int a, int b, int idx) {
    if (a <= l && r <= b) return seg[idx];
    if (l > b || r < a) return 1e9;
    int mid = (l+r)/2;
    return min(query(l, mid, a, b, 2*idx), query(mid+1, r, a, b, 2*idx+1));
}

void initialize(int N) {
    for (int i = 1; i < maxN<<1; ++i) seg[i] = 1e9;
    for (int i = 1; i <= N; ++i) update(1, 100000, i, i-1, 1);
}

void add_arc(int u, int v) {
    update(1, 100000, v+1, u+1, 1);
}

bool is_reachable(int u, int v, int t) {
    u++, v++, t++;
    if (t < u) return 1;
    if (t > v) return query(1, 100000, v+1, t, 1) < u;
    return 0;
}
