#include <bits/stdc++.h>
#define ll long long
#include "mergedmedian.h"
//#include "grader.cpp"
using namespace std;

const int maxN = 1e5 + 10;
ll A[maxN], B[maxN];

ll find_merged_median(int N) {
    int l = 0, r = N;
    while (l < r) {
        int mid = (l+r)/2;
        A[mid] = alice(mid);
        B[N-mid-1] = bob(N-mid-1);
        if (B[N-mid-1] <= A[mid]) r = mid;
        else l = mid+1;
    }
    if (!A[l]) A[l] = alice(l);
    if (l == 0) return A[l];
    if (!B[N-l]) B[N-l] = bob(N-l);
    return (A[l] < B[N-l] ? A[l] : B[N-l]);
}
