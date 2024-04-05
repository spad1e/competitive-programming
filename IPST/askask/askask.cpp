#include<bits/stdc++.h>
#include "askask.h"
//#include "grader.cpp"
#define pb push_back
using namespace std;

vector<int> vv[8];

vector<int> find_bombs(int N){
    if (N != 64) {
        int L = log2(N);
        vector<vector<int>> v(L);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < L; ++j) {
                if (i & (1<<j)) v[j].pb(i);
            }
        }

        int ans = 0;
        vector<bool> a = analyse(v);
        for (int i = 0; i < L; ++i) {
            if (a[i]) {
                ans += (1 << i);
            }
        }

        return {ans, ans};
    }
    vector<vector<int>> v;
    for (int i = 0; i < 8; ++i) {
        vector<int> a;
        for (int j = 0; j < 8; ++j) {
            a.pb(8*j + i);
        }
        v.pb(a);
    }
    for (int i = 0; i < 64; i += 8) {
        vector<int> a;
        for (int j = 0; j < 8; ++j) {
            a.pb(i + j);
        }
        v.pb(a);
    }
    vv[1] = {0, 9, 18, 27, 36, 45, 54, 63}; v.pb(vv[1]);
    vv[2] = {56, 1, 10, 19, 28, 37, 46, 55}; v.pb(vv[2]);
    vv[3] = {48, 57, 2, 11, 20, 29, 38, 47}; v.pb(vv[3]);
    vv[4] = {40, 49, 58, 3, 12, 21, 30, 39}; v.pb(vv[4]);
    vv[5] = {32, 41, 50, 59, 4, 13, 22, 31}; v.pb(vv[5]);
    vv[6] = {24, 33, 42, 51, 60, 5, 14, 23}; v.pb(vv[6]);
    vv[7] = {16, 25, 34, 43, 52, 61, 6, 15}; v.pb(vv[7]);
    vector<bool> a = analyse(v);
    vector<int> ans;

    int x[2] = {-1, -1}, y[2] = {-1, -1};
    int cur = 0;
    for (int i = 0; i < 8; ++i) {
        if (a[i]) x[cur++] = i;
    }
    cur = 0;
    for (int i = 8; i < 16; ++i) {
        if (a[i]) y[cur++] = i-8;
    }
    if (x[1] == -1) x[1] = x[0];
    if (y[1] == -1) y[1] = y[0];
    int c1 = 8*y[0] + x[0];
    int c2 = 8*y[1] + x[1];
    bool inlast = 1;
    for (int i = 16; i < 23; ++i) {
        for (auto j : vv[i-15]) {
            if (j == c1 || j == c2) inlast = 0;
            if (a[i]) inlast = 0;
            if ((j == c1 || j == c2) && a[i]) return ans = {c1, c2};
        }
    }
    if (inlast) return ans = {c1, c2};
    return ans = {8*y[0] + x[1], 8*y[1] + x[0]};
}
