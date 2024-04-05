#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define st first
#define nd second
#include "dual.h"
#include "grader.cpp"

using namespace std;

deque<pll> dq;

long long dual_fuel(int N, int V, vector<int> &A, vector<int> &B) {
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        while (!dq.empty() && i - dq.front().nd >= V) dq.pop_front();
        while (!dq.empty() && dq.back().st >= A[i]) dq.pop_back();
        dq.push_back({A[i], i});
        ans += dq.front().st;
    }
    dq.clear();
    for (int i = 0; i < N; ++i) {
        while (!dq.empty() && i - dq.front().nd >= V) dq.pop_front();
        while (!dq.empty() && dq.back().st >= B[i]) dq.pop_back();
        dq.push_back({B[i], i});
        ans += dq.front().st;
    }
    return ans;
}
