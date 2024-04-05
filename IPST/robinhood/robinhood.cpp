#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pii pair<int, int>
#define st first
#define nd second
#define pb push_back
#include "robinhood.h"
//#include "grader.cpp"
using namespace std;

const int maxN = 5e5 + 10;
const int maxL = log2(maxN) + 1;

int mx[maxN], sz[maxN], up[maxN];
int prt[maxN], lc[maxN], rc[maxN], root=0;
int Ar[maxN], in[maxN], out[maxN], t;
pii mem[maxN], seg[4*maxN];
bool mark[maxN];
vector<int> anc[maxN];

int find_sz(int i, int prtt=0) {
    sz[i] = 1;
    if (lc[i] != 0 && lc[i] != prtt && !mark[lc[i]]) sz[i] += find_sz(lc[i], i);
    if (rc[i] != 0 && rc[i] != prtt && !mark[rc[i]]) sz[i] += find_sz(rc[i], i);
    if (prt[i] != 0 && prt[i] != prtt && !mark[prt[i]]) sz[i] += find_sz(prt[i], i);
    return sz[i];
}

int find_centroid(int i, int m, int prtt=0) {
    if (lc[i] != 0 && lc[i] != prtt && !mark[lc[i]] && sz[lc[i]] > m/2) return find_centroid(lc[i], m, i);
    if (rc[i] != 0 && rc[i] != prtt && !mark[rc[i]] && sz[rc[i]] > m/2) return find_centroid(rc[i], m, i);
    if (prt[i] != 0 && prt[i] != prtt && !mark[prt[i]] && sz[prt[i]] > m/2) return find_centroid(prt[i], m, i);
    return i;
}

void filllca(int a, int lca, int prtt) {
    anc[a].pb(lca);
    if (lc[a] != 0 && lc[a] != prtt && !mark[lc[a]]) filllca(lc[a], lca, prtt);
    if (rc[a] != 0 && rc[a] != prtt && !mark[rc[a]]) filllca(rc[a], lca, prtt);
}

void decom(int x=1, int prtt=0) {
    int c = find_centroid(x, find_sz(x));
    mark[c] = 1;

    up[c] = prtt;
    if (lc[c] != 0 && !mark[lc[c]]) decom(lc[c], c);
    if (rc[c] != 0 && !mark[rc[c]]) decom(rc[c], c);
    if (prt[c] != 0 && !mark[prt[c]]) decom(prt[c], c);
    mark[c] = 0;
    int cur = c, prev = 0;
    while (cur != 0 && !mark[cur]) {
        filllca(cur, cur, prev);
        prev = cur;
        cur = prt[cur];
    }
}

void dfs(int a) {
    if (a==0) return;
    in[a] = t++;
    dfs(lc[a]);
    dfs(rc[a]);
    out[a] = t++;
}

void build(int l, int r, int idx) {
    if (l==r) {seg[idx] = {Ar[l], l}; return;}
    int mid = (l+r)/2;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    seg[idx] = max(seg[2*idx], seg[2*idx+1]);
}

pii q(int l, int r, int a, int b, int idx) {
    if (a <= l && r <= b) return seg[idx];
    if (l > b || r < a) return {0, 0};
    int mid = (l+r)/2;
    return max(q(l, mid, a, b, 2*idx), q(mid+1, r, a, b, 2*idx+1));
}

int construct(int l, int r, int from, int N) {
    if (l > r) return 0;
    int mx = q(1, N, l, r, 1).nd;
    prt[mx] = from;
    lc[mx] = construct(l, mx-1, mx, N);
    rc[mx] = construct(mx+1, r, mx, N);
    return mx;
}

void initialize(vector<int> A, int M) {
    int N = A.size();
    int cur = 0;
    for (int i = 1; i <= N; ++i) Ar[i] = A[i-1];
    build(1, N, 1);
    root = construct(1, N, 0, N);
    decom();
    dfs(root);
    for (int i = 1; i <= N; ++i) mem[i] = {1e9, 1e9};
    add(0);
}

int ask(int V) {
    int cur = ++V, ans = 1e9, cnt = 0;
    while (cur != 0) {
        ans = min(ans, Ar[anc[V][cnt]]+mem[cur].nd);
        if (in[cur] <= in[V] && out[V] <= out[cur]) ans = min(ans, mem[cur].st);
        cur = up[cur];
        cnt++;
    }
    return ans;
}

void add(int V) {
    int cur = ++V, cnt = 0;
    while (cur != 0) {
        if (in[cur] <= in[V] && out[V] <= out[cur]) mem[cur].nd = min(mem[cur].nd, -Ar[V]/2);
        else mem[cur].st = min(mem[cur].st, Ar[anc[V][cnt]]-Ar[V]/2);
        cur = up[cur];
        cnt++;
    }
}
