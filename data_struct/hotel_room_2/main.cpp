#include <bits/stdc++.h>
#include "student.h"
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <int> R(N + 1);
    for (int i = 1; i <= N; i++) cin >> R[i];

    hotel h(R);
    while (true) {
        int A, B, C, D;
        char opr;
        cin >> opr;
        
        if (opr == 'q') break;
        else if (opr == 'n') h.next_day();
        else if (opr == 'i') {
            cin >> A >> B;

            vector <pair <int, int>> result = h.check_in(A, B);
            for (auto v : result) cout << v.first << ' ' << v.second << '\n';
        }
        else if (opr == 'o') {
            cin >> C >> D;
            
            cout << h.check_out(C, D) << '\n';
        }
    }
    return 0;
}