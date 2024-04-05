#pragma GCC optimize("O3")
#include<bits/stdc++.h>
//#include <grader.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define st first
#define nd second
#define pb push_back
#define INF INT_MAX
#define db double
using namespace std;
const int N = 1e5 + 10;
vector<int> adj[N], reach[N], reach_prt[N], fw[N][2];
vector<vector<int>> query;
int sz[N], up[N], dist[N][20], lvl[N];
bool mark[N];
void add(int i, int j, int k) {
    int n = fw[j][k].size();
    for (; i < n; i += i&-i) fw[j][k][i]++;
}
int get(int i, int j, int k) {
    int n = fw[j][k].size(), ret = 0;
    for (; i > 0; i -= i&-i) ret += fw[j][k][i];
    return ret;
}
int dfs(int i, int prt=0) {
    sz[i] = 1;
    for (auto j : adj[i]) if (j != prt && !mark[j]) sz[i] += dfs(j, i);
    return sz[i];
}
int find_centroid(int i, int m, int prt=0) {
    for (auto j : adj[i]) if (j != prt && !mark[j] && sz[j] > m/2) return find_centroid(j, m, i);
    return i;
}
void dfs2(int i, int lev, int prt=0) {
    if (i!=prt) dist[i][lev] = dist[prt][lev]+1;
    for (auto j : adj[i]) if (j != prt && !mark[j]) dfs2(j, lev, i);
}
void decom(int x=1, int prt=0) {
    int cur = find_centroid(x, dfs(x));
    mark[cur] = 1;
    up[cur] = prt;
    lvl[cur] = lvl[prt]+1;
    dfs2(cur, lvl[cur], cur);
    for (auto j : adj[cur]) if (!mark[j]) decom(j, cur);
}
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    decom();
    while (q--) {
        int t, v, k; cin >> t;
        if (t==1) cin >> v >> k, query.pb({v, k});
        if (t==2) cin >> v, query.pb({v});
    }
    for (auto w : query) {
        if (w.size()==2) {
            int v = w[0], cur = w[0], k = w[1], dis = 0;
            while (1) {
                reach[cur].pb(-k+dis);
                if (!up[cur]) break;
                dis = dist[v][lvl[up[cur]]];
                reach_prt[cur].pb(-k+dis);
                cur = up[cur];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        sort(reach[i].begin(), reach[i].end());
        sort(reach_prt[i].begin(), reach_prt[i].end());
        reach[i].resize(unique(reach[i].begin(), reach[i].end()) - reach[i].begin());
        reach_prt[i].resize(unique(reach_prt[i].begin(), reach_prt[i].end()) - reach_prt[i].begin());
        fw[i][0].resize(reach[i].size()+2);
        fw[i][1].resize(reach_prt[i].size()+2);
    }
    for (auto w : query) {
        if (w.size()==2) {
            int v = w[0], cur = w[0], k = w[1], dis = 0;
            while (1) {
                int idx = upper_bound(reach[cur].begin(), reach[cur].end(), -k+dis) - reach[cur].begin();
                add(idx, cur, 0);
                if (!up[cur]) break;
                dis = dist[v][lvl[up[cur]]];
                idx = upper_bound(reach_prt[cur].begin(), reach_prt[cur].end(), -k+dis) - reach_prt[cur].begin();
                add(idx, cur, 1);
                cur = up[cur];
            }
        }
        if (w.size()==1) {
            int ans = 0, dis = 0, v = w[0], cur = w[0];
            while (1) {
                int idx = upper_bound(reach[cur].begin(), reach[cur].end(), -dis) - reach[cur].begin();
                ans += get(idx, cur, 0);
                if (!up[cur]) break;
                dis = dist[v][lvl[up[cur]]];
                idx = upper_bound(reach_prt[cur].begin(), reach_prt[cur].end(), -dis) - reach_prt[cur].begin();
                ans -= get(idx, cur, 1);
                cur = up[cur];
            }
            cout << ans << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
