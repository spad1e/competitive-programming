#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int MX = 5e2 + 3;

char access[MX][MX];
int access_level_d[MX], group[MX], cnt, cntg;
int vis[MX], mt[MX], matched[MX];
string s[MX];
map<string, int> ex;
map<int, vector<int>> mp;
vector<int> adj[MX<<1]; //in = i, out = i+cnt

bool try_kuhn(int u) {
  if (vis[u]) return 0;
  vis[u] = 1;
  for (auto v : adj[u]) {
    v -= cnt;
    if (!mt[v] || try_kuhn(mt[v])) { mt[v] = u; return 1; }
  }
  return 0;
}

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> access[i][j];
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) s[j] += access[i][j];
    if (!ex.count(s[j])) ex[s[j]] = ++cnt;
    mp[ex[s[j]]].push_back(j);  
  }
  for (int j = 1; j <= m; ++j) for (int k = 1; k <= m; ++k) {
    int jj = ex[s[j]], kk = ex[s[k]];
    if (jj == kk) continue;
    bool submask = 1;
    for (int i = 0; i < n; ++i) if (s[j][i] == '0' && s[k][i] != '0') { submask = 0; break; }
    if (!submask) continue;
    adj[kk].push_back(jj+cnt);
  }
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 1; j <= cnt; ++j) vis[j] = 0;
    try_kuhn(i);
  }
  int max_matching = 0;
  mt[0] = -1;
  for (int i = 1; i <= cnt; ++i) if (mt[i]) matched[mt[i]] = 1;
  for (int i = 1; i <= cnt; ++i) {
    if (matched[i]) continue;
    cntg++;
    int cntl = 1;
    for (int u = i; mt[u] != -1; u = mt[u]) {
      for (auto x : mp[u]) group[x] = cntg, access_level_d[x] = ++cntl;
    }
  }
  cout << cntg << nl;
  for (int i = 1; i <= m; ++i) cout << group[i] << " \n"[i==m];
  for (int i = 1; i <= m; ++i) cout << access_level_d[i] << " \n"[i==m];
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= cntg; ++j) {
    int l = 1;
    for (int k = 1; k <= m; ++k) if (group[k] == j && access[i][k] == '1') l = max(l, access_level_d[k]);
    cout << l << " \n"[j==cntg];
  }
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}