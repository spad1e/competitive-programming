#include <bits/stdc++.h>
#include "lingling.h"
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define st first
#define nd second
#define pb push_back
#define INF INT_MAX
using namespace std;

const int N = 2e5 + 10;

int fw[N], idx[N];
ll qs[N];
int cnt = 1;

int query(int i) {
    int ret = 0;
    for (; i > 0; i -= i&-i) ret += fw[i];
    return ret;
}

void update(int i) {
    for (; i < N; i += i&-i) fw[i]--;
}

void init_monkeys(vector<int> P, int Q){
    int n = P.size();

//    for (int i = 1; i <= n; ++i) fw[i] = i&-i;
//    ll sum = 0, sumP = 0, cur = 0;
//    qs[0] = 0;
//    idx[0] = -1;
//    for (int i = 0; i < n; ++i) {
//        cur += query(P[i]);
//        update(P[i]+1);
//        sum += i;
//        sumP += P[i];
//        if (sum == sumP) {
//            idx[cnt] = i;
//            qs[cnt] = qs[cnt-1] + cur;
//            cur = 0;
//            cnt++;
//        }
//    }
}

ll minimum_branches(int L, int R){
    auto i = lower_bound(idx, idx+cnt, L-1);
    auto j = lower_bound(idx, idx+cnt, R);
    if (*i != L-1 || *j != R) return -1;
    return qs[j-idx] - qs[i-idx];
}


int main(){
  int n;
  scanf("%d",&n);
  std::vector<int> P;
  P.reserve(n);
  int x;
  for(int i = 0; i < n; i++){
    scanf("%d", &x);
    P.push_back(x);
  }
  int Q;
  scanf("%d",&Q);
  init_monkeys(P, Q);
  for(int i = 0; i < Q; i++){
    int l, r;
    scanf("%d%d",&l,&r);
    long long output = minimum_branches(l, r);
    printf("%lld\n",output);
  }
  return 0;
}
