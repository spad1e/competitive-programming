#include <bits/stdc++.h>
#include "findhome.h"
//#include "grader.cpp"
#define pb push_back
#define st first
#define nd second
using namespace std;

vector<int> adj[330];
bool close[330];
int best[330];
int dis[330][330];
int new_dis[330];

int find_home(int N, int M, vector<pair<int, int>> R) {
    for (int i = 0; i < M; ++i) {
        int a = R[i].st+1;
        int b = R[i].nd+1;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<int> q;

    for (int i = 1; i <= 100; ++i) {
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dis[i][j] = INT_MAX;
        for (int i = 1; i <= N; ++i) {
            if (close[i]) continue;
            dis[i][i] = 0;
            q.push(i);
            while (!q.empty()) {
                int a = q.front(); q.pop();
                for (auto b : adj[a]) {
                    if (close[b]) continue;
                    if (dis[i][b] > dis[i][a]+1) {
                        dis[i][b] = dis[i][a]+1;
                        q.push(b);
                    }
                }
            }
        }
        for (int j = 1; j <= N; ++j) best[j] = 0;
        for (int j = 1; j <= N; ++j) {
            if (close[j]) continue;
            for (auto k : adj[j]) {
                if (close[k]) continue;
                for (int k = 1; k <= N; ++k) new_dis[k] = INT_MAX;
                new_dis[k] = 1;
                q.push(k);
                while (!q.empty()) {
                    int a = q.front(); q.pop();
                    for (auto b : adj[a]) {
                        if (close[b]) continue;
                        if (new_dis[b] > new_dis[a]+1) {
                            new_dis[b] = new_dis[a]+1;
                            q.push(b);
                        }
                    }
                }
                int cnt = 0;
                for (int l = 1; l <= N; ++l) {
                    if (close[l]) continue;
                    cnt += (dis[j][l] == new_dis[l]);
                }
                best[j] = max(best[j], cnt);
            }
        }
        best[0] = INT_MAX;
        int mn = 0;
        for (int j = 1; j <= N; ++j) {
            if (close[j]) continue;
            if (best[mn] > best[j]) {
                mn = j;
            }
        }
        int ret = check(mn-1);
        ret++;
        if (ret == mn) return ret-1;
        for (int k = 1; k <= N; ++k) new_dis[k] = INT_MAX;
        new_dis[ret] = 1;
        q.push(ret);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (auto b : adj[a]) {
                if (close[b]) continue;
                if (new_dis[b] > new_dis[a]+1) {
                    new_dis[b] = new_dis[a]+1;
                    q.push(b);
                }
            }
        }
        for (int l = 1; l <= N; ++l) {
            if (dis[mn][l] != new_dis[l]) close[l] = 1;
        }
    }
    return 0;
}
