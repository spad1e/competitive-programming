#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

char c[3][3];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool outbound(int x, int y) {
  return (x < 0 || y < 0 || x > 2 || y > 2);
}

int main() {
  for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> c[i][j];
  vector<string> s;
  for (int x = 0; x < 3; ++x) for (int y = 0; y < 3; ++y) {
    for (int k1 = 0; k1 < 8; ++k1) for (int k2 = 0; k2 < 8; ++k2) {
      if (outbound(x+dx[k1], y+dy[k1]) || outbound(x+dx[k2], y+dy[k2])) continue;
      if (k1 == k2) continue;
      string cur = "";
      cur += c[x+dx[k1]][y+dy[k1]];
      cur += c[x][y];
      cur += c[x+dx[k2]][y+dy[k2]];
      s.push_back(cur);
    }
  }
  sort(s.begin(), s.end());
  cout << s.front() << '\n';
}