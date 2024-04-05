#include <bits/stdc++.h>
#include "inversion.h"
//#include "grader.cpp"
#define ll long long
#define pb push_back
using namespace std;

vector<ll> v;
int fw[100010];

void update(int i, int val) {for (; i < 100010; i += i&-i) fw[i] += val;}
int query(int i) {int ret = 0; for (; i > 0; i -= i&-i) ret += fw[i]; return ret;}

vector<int> find_permutation(int N, ll inversion) {
    v.pb(inversion);
    for (int i = 1; i < N; ++i) v.pb(swap_and_report(0, i));
    for (int i = 1; i <= N; ++i) update(i, 1);
    vector<int> ans;
    for (int i = N-1, j = 0; i >= 0; --i, ++j) {
        int order = -(v[0]-v[i]-N+j-1)/2;
        int l = 1, r = N;
        while (l < r) {
            int mid = (l+r)/2;
            if (query(mid) < order) l = mid+1;
            else r = mid;
        }
        update(l, -1);
        ans.pb(l);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
