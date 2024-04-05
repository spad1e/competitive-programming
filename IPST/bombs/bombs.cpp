#include <bits/stdc++.h>
#define st first
#define nd second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#include "bombs.h"
//#include "grader.cpp"
using namespace std;

ll prev_T = -1e18, shift = 0, ans;

priority_queue<ll> L;
priority_queue<ll, vector<ll>, greater<ll>> R;

void initialize(int N) {
    L.push(-1e18);
    R.push(1e18);
}

ll max_hp_loss(int X, int T, int A, int P) {
    ll x = X, t = T, a = A, p = P;
    if (prev_T == -1e18) prev_T = t;
    ll dis = p*(t-prev_T);
    shift += dis;
    if (x <= L.top()-shift) {
        L.push(x+shift);
        L.push(x+shift);
        R.push(L.top()-2*shift);
        L.pop();
        ans += a-(R.top()+shift-x);
    }
    else {
        R.push(x-shift);
        R.push(x-shift);
        L.push(R.top()+2*shift);
        R.pop();
        ans += a-(x-L.top()+shift);
    }

    prev_T = t;
    return ans;
}