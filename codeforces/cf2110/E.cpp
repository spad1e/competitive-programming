#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int p[MX], v[MX], deg[MX<<1], mark[MX<<1], walk[MX], ans[MX], c;
vector<pii> adj[MX<<1];

void check_connect(int u) {
  mark[u] = 1;
  for (auto [v, idx] : adj[u]) {
    if (!mark[v]) check_connect(v);
  }
}

void dfs(int u) {
  while (!adj[u].empty()) {
    auto [v, idx] = adj[u].back(); adj[u].pop_back();
    if (walk[idx]) continue;
    walk[idx] = 1;
    dfs(v);
    ans[++c] = idx;
  }
}

void solve() {
  int n; cin >> n;
  vector<int> vP, vV;
  rep(i, 1, n) {
    cin >> p[i] >> v[i];
    vP.pb(p[i]); vV.pb(v[i]);
  }
  sort(all(vP)); sort(all(vV));
  vP.resize(unique(all(vP)) - vP.begin());
  vV.resize(unique(all(vV)) - vV.begin());
  int P = vP.size(), V = vV.size();
  rep(i, P+V) adj[i].clear(), deg[i] = 0;
  rep(i, 1, n) {
    p[i] = lb(all(vP), p[i]) - vP.begin();
    v[i] = lb(all(vV), v[i]) - vV.begin();
    adj[p[i]].emplace_back(v[i] + P, i);
    adj[v[i] + P].emplace_back(p[i], i);  
    deg[p[i]]++; deg[v[i] + P]++;
  }
  int cnt = 0;
  rep(i, P+V) mark[i] = 0;
  rep(i, P+V) if (!mark[i]) check_connect(i), cnt++; 
  if (cnt != 1) return void(cout << "NO" << nl);
  int cnt_odd_deg = 0, o = 0;
  rep(i, P+V) if (deg[i]%2) o = i, cnt_odd_deg++;
  if (cnt_odd_deg != 0 && cnt_odd_deg != 2) return void(cout << "NO" << nl);
  c = 0;
  rep(i, 1, n) walk[i] = 0;
  dfs(o);
  cout << "YES" << nl;
  rep(i, 1, c) cout << ans[i] << " ";
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}