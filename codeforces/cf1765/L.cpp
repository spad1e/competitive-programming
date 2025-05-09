#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;

const char nl = '\n';
const int MX = 2e5 + 3;

map<int, priority_queue<pair<int, int>>> work[7];
map<string, int> days_to_num = {{"Sunday", 0}, {"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}, {"Saturday", 6}};
vector<int> days_of_work[MX], a[MX];
int ans[MX], h[MX], idx[MX], cnt;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    while (x--) { 
      string s; cin >> s; 
      days_of_work[i].push_back(days_to_num[s]); 
    }
  }
  for (int i = 1; i <= m; ++i) cin >> h[i];
  for (int i = 1; i <= k; ++i) {
    int x; cin >> x;
    while(x--) { 
      int y; cin >> y; 
      a[i].push_back(y); 
    }
  }
  for (int i = 1; i <= k; ++i) {
    int emp = a[i][0];
    for (auto x : days_of_work[emp]) {
      work[x][emp].emplace(-i, 0);
    }
  }

  int hidx = 1;
  for (int ii = 1; cnt < k; ++ii) {
    if (ii == h[hidx] && ++hidx) continue;
    vector<int> to_update;
    int d = ii%7;
    for (auto &[j, pq] : work[d]) {
      while (!pq.empty()) {
        auto [project_no, stage] = pq.top(); pq.pop();
        project_no *= -1, stage *= -1;
        if (idx[project_no] > stage) continue;
        else {
          to_update.push_back(project_no);
          idx[project_no]++;
          break;
        }
      }
    }
    for (auto i : to_update) {
      if (idx[i] >= a[i].size()) {
        cnt++;
        ans[i] = ii;
        continue;
      } 
      int emp = a[i][idx[i]];
      for (auto x : days_of_work[emp]) {
        work[x][emp].emplace(-i, -idx[i]);
      }
    }
    for (auto it = work[d].begin(); it != work[d].end();) {
      auto &[j, pq] = *it;
      if (pq.empty()) work[d].erase(it++);
      else it++;
    }
  }
  for (int i = 1; i <= k; ++i) cout << ans[i] << " \n"[i==k];
}
 
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}