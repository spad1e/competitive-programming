#include <bits/stdc++.h>
//#include "grader.cpp"
#define pb push_back
using namespace std;

const int N = 6e4+10;
vector<int> x[1000010], y[1000010], primes;
int posy[N], posx[N];
bool mark[N];

void init_land(int N, int M, int P, vector<int> A, vector<int> B) {
    for (int i = 2; i <= 1010; ++i) {
        if (mark[i]) continue;
        primes.pb(i);
        for (int j = i; j <= 1010; j += i) mark[j] = 1;
    }
    for (int i = 0; i < N; ++i) {
        int cur = A[i];
        for (auto j : primes) {
            while (cur % (j*j) == 0) cur /= j*j;
        }
        x[cur].pb(i);
        posx[i] = cur;
    }
    for (int i = 0; i < M; ++i) {
        int cur = B[i];
        for (auto j : primes) {
            while (cur % (j*j) == 0) cur /= j*j;
        }
        y[cur].pb(i);
        posy[i] = cur;
    }
}

long long answer_query(int r1, int c1, int r2, int c2){
    long long ans = 0;
    if (r2-r1 <= c2-c1) {
        for (int i = r1; i <= r2; ++i) {
            ans += (upper_bound(y[posx[i]].begin(), y[posx[i]].end(), c2) - upper_bound(y[posx[i]].begin(), y[posx[i]].end(), c1-1));
        }
    }
    else {
        for (int i = c1; i <= c2; ++i) {
            ans += (upper_bound(x[posy[i]].begin(), x[posy[i]].end(), r2) - upper_bound(x[posy[i]].begin(), x[posy[i]].end(), r1-1));
        }
    }
    return ans;
}

