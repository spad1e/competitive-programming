#include "bits/stdc++.h"
#include "magic.h"
//#include "grader.cpp"
#define pb push_back
#define st first
#define nd second
#define INF INT_MAX
#define pii pair<int, int>
#define ll long long
using namespace std;

const int N = 2e5 + 10;

vector<pii> adj[N];
int dis[N][20];
bool vis[N][20];
priority_queue<pair<int, pii>> pq;

vector<int> magic(int N, int M, int Q, vector<int> U, vector<int> V, vector<vector<int>> q){
    vector<int> W(M, INF);
    for (int i = 0; i < Q; ++i) if (q[i][0] == 0) W[q[i][1]] = i;
    for (int i = 0; i < M; ++i) {
        adj[V[i]].pb({U[i], W[i]});
    }

    pq.push({INF, {0, 0}});
    dis[0][0] = INF;
    while (!pq.empty()) {
        auto [a, k] = pq.top().nd; pq.pop();
        if (vis[a][k]) continue;
        vis[a][k] = 1;
        if (k < 10 && dis[a][k+1] < dis[a][k]) {
            dis[a][k+1] = dis[a][k];
            pq.push({dis[a][k+1], {a, k+1}});
        }
        for (auto [b, t] : adj[a]) {
            if (t >= dis[a][k]) {
                if (dis[b][k] < dis[a][k]) {
                    dis[b][k] = dis[a][k];
                    pq.push({dis[b][k], {b, k}});
                }
            }
            else {
                if (dis[b][k] < t) {
                    dis[b][k] = t;
                    pq.push({dis[b][k], {b, k}});
                }
                if (k < 10 && dis[b][k+1] < dis[a][k]) {
                    dis[b][k+1] = dis[a][k];
                    pq.push({dis[b][k+1], {b, k+1}});
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < Q; ++i) {
        if (q[i][0] == 0) ans.pb(-1);
        else ans.pb((dis[q[i][1]][q[i][2]] > i ? 1 : 0));
    }
    return ans;
}
