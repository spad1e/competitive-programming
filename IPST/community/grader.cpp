#include "community.h"
#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define st first
#define nd second
#define pb push_back
using namespace std;

const int N = 200020;
const int M = 1e9 + 7;

ll dp[N], t[N], tt[N], W[N], p[N];
ll fw[N][2];
ll sum = 0;
vector<pii> v;

void update(int i, int val, int j) {
    for (; i < N; i += i&-i) {
        fw[i][j] += val;
        fw[i][j] %= M;
    }
}

ll query(int i, int j) {
    ll ret = 0;
    for (; i > 0; i -= i&-i) {
        ret += fw[i][j];
        ret %= M;
    }
    return ret;
}



int minimum_cost(int nn, vector<int> ww){
    int n = nn;
    for (int i = 1; i <= n; ++i) {
        W[i] = ww[i-1];
        v.pb({W[i], i});
    }

    p[0] = 1;
    for (int i = 1; i < N; ++i) {
        p[i] = (2*p[i-1]%M);
    }
    dp[1] = 4, t[1] = 7, tt[1] = p[n-1]*(t[1]-1)%M;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (4*dp[i-1]+2*((i%2)+1))%M;
        t[i] = (4*t[i-1]+3)%M;
        tt[i] = p[n-i]*(t[i]-1)%M;
    }

    sort(v.begin(), v.end());


    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int w = v[i-1].st;
        int idx = v[i-1].nd;
        ans += w*(tt[idx] - (query(idx, 0)-1) - (dp[idx]*(query(n, 1)-query(idx,1))%M))%M;
        ans = (ans%M+M)%M;
        update(idx, dp[idx], 0);
        update(idx, 1, 1);
    }

    return ((ans - v[0].st)%M+M)%M;
}


int main(){
  int N;
  scanf("%d",&N);
  vector<int> w;
  w.reserve(N);
  for(int i = 0; i < N; i++){
    int x;
    scanf("%d",&x);
    w.push_back(x);
  }
  printf("%d\n", minimum_cost(N, w));
  return 0;
}
