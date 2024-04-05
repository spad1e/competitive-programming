#include<bits/stdc++.h>
#include "goatforget.h"
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define st first
#define nd second
#define pb push_back
#define INF INT_MAX
using namespace std;

static int n, m, q;
static std::vector<int> g[128];
static int goat;
static int tcount;

int talk_tae(int x){
  if(x < 0 || x >= n){
    printf("Invalid talk\n");
    fflush(stdout);
    exit(0);
  }
  tcount++;
  if(tcount > q){
    printf("Too many talks\n");
    fflush(stdout);
    exit(0);
  }
  auto it = std::lower_bound(g[goat].begin(), g[goat].end(), x);
  int ylo = -1;
  int yhi = -1;
  if(it != g[goat].end()) yhi = *it;
  if(it != g[goat].begin()){
    it--;
    ylo = *it;
  }
  if(ylo != -1 && yhi != -1){
    if(abs(ylo - x) > abs(yhi - x)) return goat = yhi;
    else return goat = ylo;
  }else if(ylo != -1){
    return goat = ylo;
  }else{
    return goat = yhi;
  }
}

const int N = 510;
int adj[N][N];
bool vis[N];

void srch(int i, int l, int r) {
    if (l > r) return;
    int mid = (l+r)/2;
    int ret = talk_tae(mid);
    int dis = abs(mid-ret);
    talk_tae(i);
    if (ret < l || ret > r) {
        for (int j = l; j <= r; ++j) {
            adj[i][j] = -1;
            adj[j][i] = -1;
        }
    }
    adj[i][ret] = 1;
    adj[ret][i] = 1;
    if (ret < mid) {
        for (int j = ret+1; j < mid+dis; ++j) {
            adj[i][j] = -1;
            adj[j][i] = -1;
        }
        srch(i, l, ret-1);
        srch(i, mid+dis, r);
    }
    if (ret > mid) {
        for (int j = max(0, mid-dis); j < ret; ++j) {
            adj[i][j] = -1;
            adj[j][i] = -1;
        }
        srch(i, l, mid-dis-1);
        srch(i, ret+1, r);
    }
    if (ret == mid) {
        srch(i, l, ret-1);
        srch(i, ret+1, r);
    }
}

void dfs(int i, int n) {
    vis[i] = 1;
    int l = -1;
    adj[i][n] = -1;
    for (int j = 0; j <= n; ++j) {
        if (adj[i][j] == 0 && l == -1) l = j;
        if (adj[i][j] != 0 && l != -1) {
            srch(i, l, j-1);
            l = -1;
        }
    }

    for (int j = 0; j < n; ++j) {
        if (vis[j]) continue;
        if (adj[i][j] == 1) {
            talk_tae(j);
            dfs(j, n);
            talk_tae(i);
        }
    }
}

vector<vector<int>> recover_map(int n, int m, int q) {
    dfs(0, n);

    vector<vector<int>> v;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (adj[i][j] == 1) v.pb({i, j});
        }
    }

    return v;
}

int main(){
  scanf("%d%d%d",&n,&m,&q);
  std::set<std::pair<int,int> > template_edges;
  for(int i = 0; i < m; i++){
    int u, v;
    scanf("%d%d",&u,&v);
    if(u > v) std::swap(u, v);
    g[u].push_back(v);
    g[v].push_back(u);
    template_edges.insert(std::make_pair(u, v));
  }
  for(int i = 0; i < n; i++){
    std::sort(g[i].begin(), g[i].end());
  }
  std::vector<std::vector<int> > raw_edges = recover_map(n, m, q);
  for (auto i : raw_edges) {
    cout << i[0] << " " << i[1] << '\n';
  }
  if(raw_edges.size() != m){
    printf("Invalid answer\n");
    fflush(stdout);
    exit(0);
  }
  std::set<std::pair<int,int> > edges;
  for(auto e : raw_edges){
    if(e.size() != 2){
      printf("Invalid answer\n");
      fflush(stdout);
      exit(0);
    }
    if(e[0] < 0 || e[0] >= n || e[1] < 0 || e[1] >= n || e[0] == e[1]){
      printf("Invalid answer\n");
      fflush(stdout);
      exit(0);
    }
    std::pair<int, int> edge = std::make_pair(e[0], e[1]);
    if(edge.first > edge.second) std::swap(edge.first, edge.second);
    if(edges.count(edge)){
      printf("Invalid answer\n");
      fflush(stdout);
      exit(0);
    }
    edges.insert(edge);
  }
  if(edges == template_edges){
    printf("Correct answer: %d\n", tcount);
  }else{
    printf("Wrong answer\n");
  }
  return 0;
}
