#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int MX = 2e5 + 3;
ll a[MX];

int main() {
  int n; cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
  for (int i = 0; i < n; ++i) a[i] = min(a[i], 2*(sum-a[i]));
  sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  cout << sum/3 << '\n';
}