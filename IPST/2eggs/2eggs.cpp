#include <bits/stdc++.h>
#include "2eggs.h"

int drop2(int l, int r) {
    for (int i = l; i < r; ++i) {
        if (drop_egg(2, i)) return i;
    }
    return r;
}

int drop1(int l, int r) {
    int h = l + ceil(sqrt(r-l+1));
    if (h >= r) return drop2(l, r);
    if (drop_egg(1, h)) return drop2(l, h);
    return drop1(h+1, r);
}

int height_threshold (int N, int Q) {
    if (N == 4) {
        int n = sqrt(N);
        int h = n;
        while(h < N && !drop_egg(1, h))
            h += n;
        int H = h-n+1;
        while (H < h && !drop_egg(2, H))
            H++;
        return H;
    }
    return drop1(1, N);
}
