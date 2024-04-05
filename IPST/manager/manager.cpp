#include <bits/stdc++.h>
#include "manager.h"
//#include "grader.cpp"
using namespace std;

const int maxN = 5e4 + 10;
const int B = 240;

int N;
struct node{
    int val, lc, rc;
}seg[40*maxN];

map<int, int> lft;
int root[maxN], cnt, up[maxN][B][17];

void update(int &cur, int l, int r, int x, int val) {
    cnt++;
    seg[cnt] = seg[cur];
    cur = cnt;

    if (l==r) {seg[cur].val += val; return;}
    int mid = (l+r)/2;
    if (x <= mid) update(seg[cur].lc, l, mid, x, val);
    else update(seg[cur].rc, mid+1, r, x, val);

    seg[cur].val = seg[seg[cur].lc].val + seg[seg[cur].rc].val;
}

int query(int cur, int l, int r, int x) {
    if (l==r) return (seg[cur].val > x ? l+1 : l);
    int mid = (l+r)/2;
    int freq = seg[seg[cur].rc].val;
    if (freq > x) return query(seg[cur].rc, mid+1, r, x);
    else return query(seg[cur].lc, l, mid, x-freq);
}

void initialize(int N, int Q, vector<int> A) {
    ::N = N;
    for (int i = 1; i <= N; ++i) {
        root[i] = root[i-1];
        if (lft[A[i-1]] != 0) update(root[i], 1, 50000, lft[A[i-1]], -1);
        update(root[i], 1, 50000, i, 1);
        lft[A[i-1]] = i;
    }
    for (int k = 1; k < B; ++k) {
        unordered_map<int, int> mp;
        int j = 0, cnt = 0;;
        for (int i = 1; i <= N; ++i) {
            while (j <= N && cnt <= k) {
                j++;
                mp[A[j-1]]++;
                if (mp[A[j-1]] == 1) cnt++;
            }
            up[i][k][0] = j;
            mp[A[i-1]]--;
            if (mp[A[i-1]] == 0) cnt--;
        }
    }

    for (int k = 1; k < B; ++k) {
        for (int i = N; i >= 1; --i) {
            for (int j = 1; j < 17; ++j) {
                int tmp = up[up[i][k][j-1]][k][j-1];
                if (tmp == 0) up[i][k][j] = N+1;
                else up[i][k][j] = tmp;
            }
        }
    }
}

int min_managers(int L, int R, int X) {
    L++, R++;
    if (X >= B) {
        int cnt = 0;
        while (L <= R) {
            int cur = query(root[R], 1, 50000, X);
            cnt++;
            R = cur-1;
        }
        return cnt;
    }
    else {
        int ret = 1;
        for (int i = 16; i >= 0; --i) {
            if (up[L][X][i] <= R) ret += (1<<i), L = up[L][X][i];
        }
        return ret;
    }
}
