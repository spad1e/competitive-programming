#include <bits/stdc++.h>
#include "stick.h"
//#include "grader.cpp"
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
using namespace std;

const int N = 1<<18;
vector<int> seg[N<<1];
int a[N], n;

void build(int l, int r, int idx) {
    if (l==r) {
        seg[idx].pb(a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);

    int i = 0, j = 0;
    int sz1 = seg[2*idx].size();
    int sz2 = seg[2*idx+1].size();
    vector<int> v;
    while (i < sz1 || j < sz2) {
        if (i >= sz1) v.pb(seg[2*idx+1][j++]);
        else if (j >= sz2 || seg[2*idx][i] > seg[2*idx+1][j]) v.pb(seg[2*idx][i++]);
        else v.pb(seg[2*idx+1][j++]);
    }
    seg[idx] = v;
}

vector<int> query(int l, int r, int a, int b, int idx) {
    if (a <= l && r <= b) {
        vector<int> ret;
        int sz = seg[idx].size();
        int split = min(45, sz);
        for (int i = 0; i < sz-2; ++i) {
            if (seg[idx][i] < seg[idx][i+1]+seg[idx][i+2]) {
                split = i+3;
                break;
            }
        }
        for (int i = 0; i < split; ++i) {
            ret.pb(seg[idx][i]);
        }
        return ret;
    }
    if (r < a || l > b) return {};
    int mid = (l+r)/2;
    vector<int> v1 = query(l, mid, a, b, 2*idx);
    vector<int> v2 = query(mid+1, r, a, b, 2*idx+1);
    vector<int> ret;

    int i = 0, j = 0;
    int sz1 = v1.size();
    int sz2 = v2.size();
    while ((i < sz1 || j < sz2) && i+j <= 50) {
        if (i >= sz1) ret.pb(v2[j++]);
        else if (j >= sz2 || v1[i] > v2[j]) ret.pb(v1[i++]);
        else ret.pb(v2[j++]);

        if (ret.size() >= 3) {
            int sz = ret.size();
            if (ret[sz-3] < ret[sz-1] + ret[sz-2]) break;
        }
    }
    return ret;
}

void init(int N, vector<int> X){
    n = N;
    for (int i = 0; i < n; ++i) {
        a[i+1] = X[i];
    }
    build(1, n, 1);
}

int max_length(int L, int R){
    L++, R++;
    if (R-L+1 < 3) return -1;
    vector<int> v = query(1, n, L, R, 1);
    int mx = -1;
    int sz = v.size();
    for (int i = 0; i < sz-2; ++i) {
        if (v[i] < v[i+1]+v[i+2]) {
            mx = v[i]+v[i+1]+v[i+2];
            break;
        }
    }
    return mx;
}

/*
5 3
2 4 3 2 6
1 3
2 4
0 4
*/
