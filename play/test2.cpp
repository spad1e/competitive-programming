#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const char nl = '\n';
const int MX = 1e5 + 3;

int Ki[MX], dis[MX];
vector<int> adj[MX];
vector<pii> edge;

void solve() {
  int N, M, K; cin >> N >> M >> K;
  for (int i = 1; i <= K; ++i) cin >> Ki[i];
  for (int i = 1; i <= N; ++i) dis[i] = INT_MAX;
  for (int i = 1; i <= M; ++i) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
    edge.pb({u, v});
  }
  queue<int> q;
  for (int i = 1; i <= K; ++i) dis[Ki[i]] = 0, q.push(Ki[i]);
  while (!q.empty()) {
    int a = q.front(); q.pop();
    for (auto b : adj[a]) {
      if (dis[b] > dis[a]+1) {
        dis[b] = dis[a]+1;
        q.push(b);
      }
    }
  }
  int ans = 0;
  for (auto [u, v] : edge) {
    if (dis[u] == dis[v]) ans = max(ans, dis[u]+1);
    else ans = max(ans, max(dis[u], dis[v]));
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}