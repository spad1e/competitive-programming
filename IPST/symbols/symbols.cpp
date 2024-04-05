#include<bits/stdc++.h>
#include "symbols.h"
#define ll long long
using namespace std;

int N;
int Q;
const int M = 20232566;
bool out;

ll seg[1<<18];

void update(int l, int r, int x, ll val, int idx, bool overwrite) {
    if (l==r) {
        if (overwrite) seg[idx] = val;
        else seg[idx] = min(val, seg[idx]);
        return;
    }
    int mid = (l+r)/2;
    if (x <= mid) update(l, mid, x, val, 2*idx, overwrite);
    else update(mid+1, r, x, val, 2*idx+1, overwrite);

    seg[idx] = (seg[2*idx] * seg[2*idx+1]) % M;
}


void explore_site(int N, int Q) {
    ::N = N;
    ::Q = Q;
    memset(seg, 1, sizeof(seg));
    for (int i = 1; i <= N; ++i) {
        update(1, N, i, 26, 1, 1);
    }
}

int retrieve_notes(int L, int R) {
    L++, R++;
    if (R-L+1 > 26) out = 1;
    if (out) return 0;
    for (int idx = L; idx <= R; ++idx) {
        update(1, N, idx, 26-(idx-L), 1, 0);
    }
    return seg[1];
}
