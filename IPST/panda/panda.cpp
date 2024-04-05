#include<bits/stdc++.h>
//#include "grader.cpp"
#include "panda.h"
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define st first
#define nd second
#define pb push_back
#define INF INT_MAX
using namespace std;

const int N = 1e5 + 10;
int sm[4*N][33];
multiset<int> ms[N][33];
vector<int> adj[N];
pii dis[N];

void update(int l, int r, int x, int val, int idx, int j) {
    if (l == r) {
        sm[idx][j] = val;
        return;
    }
    int mid = (l+r)/2;
    if (x <= mid) update(l, mid, x, val, 2*idx, j);
    else update(mid+1, r, x, val, 2*idx+1, j);

    sm[idx][j] = max(sm[2*idx][j], sm[2*idx+1][j]);
}

int query(int l, int r, int a, int b, int idx, int j) {
    if (b < l || a > r) return INT_MIN;
    if (l >= a && r <= b) return sm[idx][j];
    int mid = (l+r)/2;
    return max(query(l, mid, a, b, 2*idx, j), query(mid+1, r, a, b, 2*idx+1, j));
}

int n;

void initialize(int N, int M, int S, vector<vector<int>> R) {
    n = S+1;
    for (int i = 1; i <= 4*n; ++i) {
        for (int j = 1; j <= 30; ++j) {
            sm[i][j] = INT_MIN;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 30; ++j) {
            ms[i][j].insert(INT_MIN);
        }
    }
    for (int i = 0; i < M; ++i) {
        R[i][0]++;
        R[i][1]++;
    }
    for (int i = S; i < M; ++i) {
        adj[R[i][0]].pb(R[i][1]);
        adj[R[i][1]].pb(R[i][0]);
    }
    for (int i = 1; i <= N; ++i) dis[i] = {INT_MAX, 0};
    queue<int> q;
    for (int i = 1; i <= S+1; ++i) {
        dis[i] = {0, 0};
        q.push(i);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (auto b : adj[a]) {
                if (dis[b].st > dis[a].st+1) {
                    dis[b] = {dis[a].st+1, i};
                    q.push(b);
                }
            }
        }
    }
}


void panda_spawn(int P, int L, int X) {
    X++;
    int S = P-dis[X].st*L;
    int pos = dis[X].nd;
    int left_edge = S - L*(pos);
    int right_edge = S - L*(n-pos+1);
    int qs = query(1, n, pos, pos, 1, L);
    int ql = query(1, n, pos, pos, 1, L+10);
    int qr = query(1, n, pos, pos, 1, L+20);
    ms[pos][L].insert(S);
    ms[pos][L+10].insert(left_edge);
    ms[pos][L+20].insert(right_edge);
    if (qs < S) update(1, n, pos, S, 1, L);
    if (ql < left_edge) update(1, n, pos, left_edge, 1, L+10); //left <=
    if (qr < right_edge) update(1, n, pos, right_edge, 1, L+20); //right =>
}

void panda_evac(int P, int L, int X) {
    X++;
    int S = P-dis[X].st*L;
    int pos = dis[X].nd;
    int left_edge = S - L*(pos);
    int right_edge = S - L*(n-pos+1);
    ms[pos][L].erase(ms[pos][L].lower_bound(S));
    ms[pos][L+10].erase(ms[pos][L+10].lower_bound(left_edge));
    ms[pos][L+20].erase(ms[pos][L+20].lower_bound(right_edge));
    S = *ms[pos][L].rbegin();
    left_edge = *ms[pos][L+10].rbegin();
    right_edge = *ms[pos][L+20].rbegin();
    update(1, n, pos, S, 1, L);
    update(1, n, pos, left_edge, 1, L+10);
    update(1, n, pos, right_edge, 1, L+20);
}

int travel(int A, int B) {
    int a = ++A;
    int b = ++B;
    if (b < a) swap(a, b);
    int ans = INT_MIN;
    for (int L = 1; L <= 10; ++L) {
        ans = max(ans, query(1, n, a, b, 1, L));
        ans = max(ans, query(1, n, b+1, n, 1, L+10) + L*b);
        ans = max(ans, query(1, n, 1, a-1, 1, L+20) + L*(n-a+1));
    }
    return ans;
}
