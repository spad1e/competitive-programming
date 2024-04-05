#include "numagain.h"
//#include "grader.cpp"
#include<bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define st first
#define nd second
#define pb push_back
#define INF INT_MAX
using namespace std;

const int N = 2e3 + 10;
const int M = 1e9 + 7;
const int K = 1e6 + 10;

int a[N];
ll t[K], dp[N][N], qs[N][N];

int find_ans(vector<int> number) {
    int n = number.size();
    for (int i = 1; i <= n; ++i) {
        a[number[i-1]]  ++;
    }
    t[0] = 1;
    for (int i = 1; i < K; ++i) t[i] = 2*t[i-1] % M;
    ll ans = 0;

    for (int i = 0; i <= 2001; ++i) qs[i][0] = 1;
    for (int i = 1; i <= 2000; ++i) {
        for (int j = 1; j <= 2000; ++j) {
            dp[i][j] = qs[i-1][j-1]*(t[a[i]]-1) % M;
            qs[i][j] = (qs[i-1][j] + dp[i][j]) % M;
            ans += dp[i][j]*i%M*j%M;
            ans %= M;
        }
    }

    memset(dp, 0, sizeof(dp));
    memset(qs, 0, sizeof(qs));

    for (int i = 0; i <= 2001; ++i) qs[i][0] = 1;
    for (int i = 2000; i >= 1; --i) {
        for (int j = 1; j <= 2000; ++j) {
            dp[i][j] = qs[i+1][j-1]*(t[a[i]]-1) % M;
            qs[i][j] = (qs[i+1][j] + dp[i][j]) % M;
            ans -= dp[i][j]*i%M*j%M;
            ans %= M;
        }
    }

    return (ans%M+M)%M;
}

