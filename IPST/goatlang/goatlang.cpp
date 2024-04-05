#include <bits/stdc++.h>
#include "goatlang.h"
//#include "grader.cpp"
#define pb push_back
using namespace std;

tuple<vector<vector<int>>, int, int> example1() {
    return {{{1, 0, 0}, {0, 2, 0}, {0, 0, 3}}, 2, 2};
}
tuple<vector<vector<int>>, int, int> example2() {
    return {{{1, 1}, {1, 0}}, 0, 1};
}

tuple<vector<vector<int>>, int, int> task1(vector<vector<int>> A, int r, int c) {
    for (auto &i : A) for (auto &j : i) if (j < 0) j += 1e9+7;
    return {A, r, c};
}
tuple<vector<vector<int>>, int, int> task2(vector<vector<int>> H, int a, int b) {
    vector<vector<int>> v = H;
    int n = v.size();
    v.pb({});
    for (int i = 0; i < n; ++i) v[i].pb(0);
    for (int i = 0; i < n; ++i) v[n].pb(v[a][i]);
    v[n].pb(1);
    return {v, n, b};
}

int C[11][11];

tuple<vector<vector<int>>, int, int> task3(vector<int> a) {
    vector<vector<int>> v(22, vector<int>(vector<int>(22)));
    C[0][0] = 1;
    for (int i = 1; i <= 10; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    v[0][0] = 1;
    v[0][21] = a[0];
    for (int i = 1; i < a.size(); ++i) {
        int cur = 2*i-1;
        v[cur][cur] = 1;
        for (int j = 0; j < i; ++j) {
            v[2*j][cur] = v[2*j][cur+1] = C[i][j];
            v[2*j][21] += C[i][j]*a[i];
        }
        v[cur][cur+1] = 1;
        v[cur][21] += a[i];
    }
    return {v, 0, 21};
}
tuple<vector<vector<int>>, int, int> task4() {
    return {{{0, 1, 1, 1, 1, 2},
             {0, 1, 1, 0, 0, 1},
             {0, 0, 0, 1, 1, 1},
             {0, 1, 0, 0, 0, 1},
             {0, 0, 0, 1, 1, 1},
             {0, 0, 0, 0, 0, 0}},
            0, 5};
}
tuple<vector<vector<int>>, int, int> task5(vector<int> D) {
    vector<vector<int>> v(11, vector<int>(vector<int>(11)));
    v[0][1] = 1;
    v[1][2] = 1;
    v[2][3] = 1;
    v[3][4] = 1;
    v[4][5] = 1;
    v[5][6] = 1;
    v[6][7] = 1;
    v[7][8] = 1;
    v[8][9] = 1;
    for (int i = 0; i < D.size(); ++i) {
        if (D[i]) v[i][10] = 1;
    }
    return {v, 0, 10};
}
tuple<vector<vector<int>>, int, int> task6(int m) {
    vector<vector<int>> v(11, vector<int>(vector<int>(11)));
    v[0][1] = 1;
    v[1][2] = 1;
    v[2][3] = 1;
    v[3][4] = 1;
    v[4][5] = 1;
    v[5][6] = 1;
    v[6][7] = 1;
    v[7][8] = 1;
    v[8][9] = 1;
    v[9][10] = 1;
    v[m-1][0] = 1;
    return {v, 0, 0};
}
