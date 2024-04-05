#include <bits/stdc++.h>
#include "coin.h"
//#include "grader.cpp"
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
using namespace std;

const int NN = 1<<18;

int fw[NN], seg[NN<<1], lz[NN<<1];
vector<pii> Rails;
int L, N, cur;

void update_fw(int i, int val) {
    for (; i < NN; i += i&-i) fw[i] += val;
}

int query_fw(int i) {
    int ret = 0;
    for (; i > 0; i -= i&-i) ret += fw[i];
    return ret;
}

void push(int idx) {
    seg[2*idx] += lz[idx];
    seg[2*idx+1] += lz[idx];
    lz[2*idx] += lz[idx];
    lz[2*idx+1] += lz[idx];
    lz[idx] = 0;
}

void update_seg(int l, int r, int a, int b, int val, int idx) {
    if (l != r) push(idx);
    if (a <= l && r <= b) {
        seg[idx] += val;
        lz[idx] += val;
        return;
    }
    if (r < a || l > b) return;
    int mid = (l+r)/2;
    update_seg(l, mid, a, b, val, 2*idx);
    update_seg(mid+1, r, a, b, val, 2*idx+1);
    seg[idx] = max(seg[2*idx], seg[2*idx+1]);
}

int query_seg(int l, int r, int a, int b, int idx) {
    if (l != r) push(idx);
    if (a <= l && r <= b) return seg[idx];
    if (r < a || l > b) return 0;
    int mid = (l+r)/2;
    return max(query_seg(l, mid, a, b, 2*idx),
               query_seg(mid+1, r, a, b, 2*idx+1));
}

int srch(int L, int targ) {
    int l = L, r = N+1;
    while (l < r) {
        int mid = (l+r)/2;
        int q = query_fw(mid) - query_fw(L-1);
        if (q > targ) r = mid;
        else l = mid+1;
    }
    return l;
}

void initialize(int N, vector<int> Rail, int L) {
    ::N = N;
    ::L = L;
    for (int i = 0; i < N; ++i) {
        Rails.pb({Rail[i], i+1});
    }
    sort(Rails.begin(), Rails.end());
}

vector<int> max_dist(vector<vector<int>> Coins) {
    int Q = Coins.size();
    vector<int> Ans(Q);
    vector<pii> Query(Q);
    for (int i = 0; i < Q; ++i) {
        Query[i] = {Coins[i][2], i};
    }
    for (int i = 1; i <= N; ++i) {
        update_fw(i, 1);
        if (i <= N-L+1) update_seg(1, N-L+1, i, i, L, 1);
    }
    sort(Query.begin(), Query.end());
    for (auto [i, idx] : Query) {
        int A = Coins[idx][0]+1;
        int B = Coins[idx][1];
        int C = Coins[idx][2];
        while (cur < N && Rails[cur].st <= C) {
            update_fw(Rails[cur].nd, -1);
            update_seg(1, N, max(1, Rails[cur].nd-L+1), Rails[cur].nd, -1, 1);
            cur++;
        }
        int ed = srch(A, B);
        int q = query_seg(1, N, A, ed, 1);
        int new_ed = srch(A, B+q);
        Ans[idx] = new_ed-1;
    }
    return Ans;
}
