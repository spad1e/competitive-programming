#include <bits/stdc++.h>
#include "onepath.h"
//#include "grader.cpp"
#define pb push_back
#define pii pair<int, int>
#define st first
#define nd second
using namespace std;

const int N = 1<<17;
int seg[N<<1], lz[N<<1], h[N], he[N], pos[N], cnt, prt[N], lvl[N], rep[N];
vector<int> adj[N];

int fi(int i) {return rep[i]==i?i:rep[i]=fi(rep[i]);}

int dfs(int i) {
    int sz = 1, mxsz = 0;
    for (auto j : adj[i]) {
        if (j==prt[i]) continue;
        prt[j] = i; lvl[j] = lvl[i]+1;
        int csz = dfs(j);
        if (csz > mxsz) mxsz = csz, h[i] = j;
        sz += csz;
    }
    return sz;
}

void decom(int i, int head) {
    he[i] = head; pos[i] = ++cnt;
    if (h[i]) decom(h[i], head);
    for (auto j : adj[i]) {
        if (j != prt[i] && j != h[i]) decom(j, j);
    }
}

void push(int idx, int l, int r) {
    int mid = (l+r)/2;
    if (lz[idx]) {
        seg[2*idx] += (mid-l+1)*lz[idx];
        lz[2*idx] += lz[idx];
        seg[2*idx+1] += (r-mid)*lz[idx];
        lz[2*idx+1] = lz[idx];
        lz[idx] = 0;
    }
}

void update_seg(int l, int r, int a, int b, int idx) {
    if (a <= l && r <= b) {
        seg[idx] += (r-l+1);
        lz[idx]++;
        return;
    }
    if (l > b || r < a) return;
    if (l!=r) push(idx, l, r);
    int mid = (l+r)/2;
    update_seg(l, mid, a, b, 2*idx);
    update_seg(mid+1, r, a, b, 2*idx+1);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

int query_seg(int l, int r, int a, int b, int idx) {
    if (a <= l && r <= b) return seg[idx];
    if (l > b || r < a) return 0;
    if (l!=r) push(idx, l, r);
    int mid = (l+r)/2;
    return query_seg(l, mid, a, b, 2*idx) + query_seg(mid+1, r, a, b, 2*idx+1);
}

void update(int a, int b) {
    for (; he[a] != he[b]; b = prt[he[b]]) {
        if (lvl[he[b]] < lvl[he[a]]) swap(a, b);
        update_seg(1, 100000, pos[he[b]], pos[b], 1);
    }
    if (pos[a] > pos[b]) swap(a, b);
    update_seg(1, 100000, pos[a]+1, pos[b], 1);
}

int query(int a, int b) {
    int ret = 0;
    for (; he[a] != he[b]; b = prt[he[b]]) {
        if (lvl[he[b]] < lvl[he[a]]) swap(a, b);
        ret += query_seg(1, 100000, pos[he[b]], pos[b], 1);
    }
    if (pos[a] > pos[b]) swap(a, b);
    ret += query_seg(1, 100000, pos[a]+1, pos[b], 1);
    return ret;
}

bool is_dangerous(int u, int v) {return !query(++u, ++v);}

void build_road(int u, int v) {update(++u, ++v);}


void initialize(int N, int M, int Q, vector<pair<int,int>> R) {
    vector<pii> mem;
    for (int i = 1; i <= N; ++i) rep[i] = i;
    for (int i = 0; i < M; ++i) {
        int u = R[i].st+1, v = R[i].nd+1;
        if (fi(u) == fi(v)) mem.pb({u, v});
        else {
            adj[u].pb(v);
            adj[v].pb(u);
            rep[fi(u)] = fi(v);
        }
    }
    dfs(1);
    decom(1, 1);
    for (auto [u, v] : mem) update(u, v);
}

/*
8 8 9
0 1
1 2
3 1
2 3
4 3
6 4
4 5
5 7
1 7 6
1 3 5
1 0 6
1 2 7
2 4 7
1 3 5
1 3 6
2 2 6
1 3 6
*/
