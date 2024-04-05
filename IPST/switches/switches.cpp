#include<bits/stdc++.h>
#include "switches.h"
#define st first
#define nd second
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pb push_back
#define INF LLONG_MAX
using namespace std;

const int N = 1e5 + 10;

vector<pll> adj[N];
priority_queue<pll> pq;

ll fw[N], dis[N], tmp[N];

void clr() {
    for (int i = 1; i < N; ++i) fw[i] = INF;
}

ll query(int i) {
    ll ret = INF;
    for (; i > 0; i -= i&-i) ret = min(ret, fw[i]);
    return ret;
}

void update(int i, ll val) {
    for (; i < N; i += i&-i) fw[i] = min(fw[i], val);
}

long long minimum_energy(int N, int M, int K, vector<int> A, vector<int> L, vector<int> R, vector<int> C){
    for (int i = 0; i < N; ++i) {
        adj[i].pb({i+1, A[i]});
        adj[i+1].pb({i, A[i]});
    }
    for (int i = 0; i < M; ++i) {
        adj[L[i]].pb({R[i]+1, C[i]});
        adj[R[i]+1].pb({L[i], C[i]});
    }
    for (int i = 0; i <= N; ++i) dis[i] = INF, tmp[i] = INF;
    dis[0] = 0;
    pq.push({dis[0], 0});

    while (!pq.empty()) {
        int a = pq.top().nd; pq.pop();
        for (auto [b, w] : adj[a]) {
            if (dis[b] > dis[a] + w) {
                dis[b] = dis[a] + w;
                pq.push({-dis[b], b});
            }
        }
    }

    while (K--) {
        clr();
        for (int i = 0; i < N; ++i) {
            update(100001-A[i], dis[i] + (ll)A[i]*A[i]);
            tmp[i+1] = min(tmp[i+1], query(100001-A[i]) - (ll)A[i]*A[i]);
        }
        clr();
        for (int i = 0; i < N; ++i) {
            update(A[i], dis[i] - (ll)A[i]*A[i]);
            tmp[i+1] = min(tmp[i+1], query(A[i]) + (ll)A[i]*A[i]);
        }
        clr();
        for (int i = N; i > 0; --i) {
            update(100001-A[i-1], dis[i] + (ll)A[i-1]*A[i-1]);
            tmp[i-1] = min(tmp[i-1], query(100001-A[i-1]) - (ll)A[i-1]*A[i-1]);
        }
        clr();
        for (int i = N; i > 0; --i) {
            update(A[i-1], dis[i] - (ll)A[i-1]*A[i-1]);
            tmp[i-1] = min(tmp[i-1], query(A[i-1]) + (ll)A[i-1]*A[i-1]);
        }

        for (int i = 0; i <= N; ++i) {
            dis[i] = tmp[i];
        }
        for (int i = 0; i <= N; ++i) pq.push({-dis[i], i});
        while (!pq.empty()) {
            int a = pq.top().nd; pq.pop();
            for (auto [b, w] : adj[a]) {
                if (dis[b] > dis[a] + w) {
                    dis[b] = dis[a] + w;
                    pq.push({-dis[b], b});
                }
            }
        }
    }

	return dis[N];
}

/*
6 4 1
1 3 8 8 5 9
0 1 5
1 4 6
2 3 4
3 5 3
*/
