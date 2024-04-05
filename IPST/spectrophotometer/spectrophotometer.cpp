#include <bits/stdc++.h>
#include "spectrophotometer.h"
using namespace std;

void sort_lasers(int N) {
    int i = 0, j = 1;
    while (j < 3*N) {
        if (!call_swap(i, j)) i++;
        j++;
    }
    i = 0, j = 1;
    while (j < 2*N) {
        if (!call_swap(i, j)) i++;
        j++;
    }
}
