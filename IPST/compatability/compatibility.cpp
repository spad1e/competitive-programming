#include <bits/stdc++.h>
#define ll long long
#include "compatibility.h"
//#include "grader.cpp"
using namespace std;

const int N = 3e3 + 10;

ll area[N], inv_area[N];

long long maximum_incompatibility(vector<vector<int>> A) {
    int m = A.size();
    int n = A[0].size();
    for (int i = 0; i < m; ++i) {
        ll sum = 0, sum2 = 0;
        for (int j = 0; j < n; ++j) {
            sum += A[i][j];
        }
        area[i] = 2*(sum - (ll)n*A[i][0]) - (A[i][n-1] - A[i][0]);
        inv_area[i] = 2*((ll)n*A[i][n-1] - sum) - (A[i][n-1] - A[i][0]);
    }

    ll mx = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            int l = 0, r = n-1;
            while (l < r) {
                int mid = (l+r+1)/2;
                bool L = (mid==0 ? 1 : A[i][mid] - A[i][mid-1] >= A[j][n-mid] - A[j][n-mid-1]);
                if (L) l = mid;
                else r = mid-1;
            }
            mx = max(mx, inv_area[j] - area[i] + (ll)2*(n-1)*((ll)A[i][l] - A[i][0] - A[j][n-1] + A[j][n-l-1]));
        }
    }
    return mx;
}
