#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool checkcondition1(ll S, ll a, ll b) {
  if (a==b) return 0;
  if (b < a) swap(a, b);
  for (int i = 1; i <= S; ++i) if (S*a+i == b) return 1;
  return 0;
}

bool checkcondition2(ll S, ll a, ll b) {
  if (a==b) return 0;
  if (b < a) swap(a, b);
  while (a < b) b = (b-1)/S;
  return a==b;
}

bool checkcondition3(ll S, ll a, ll b) {
  int depthA = -1, depthB = -1, curDepth = 0;
  ll curCnt = 1, leafCnt = 1;
  while (curCnt <= max(a, b)) {
    if (depthA == -1 && curCnt > a) depthA = curDepth;
    if (depthB == -1 && curCnt > b) depthB = curDepth;
    curCnt += leafCnt * S;
    leafCnt *= S;
    curDepth++;
  }
  return depthA != depthB;
}

int relation(ll S, ll a, ll b) {
  if (checkcondition1(S, a, b)) return 1;
  if (checkcondition2(S, a, b)) return 2;
  if (checkcondition3(S, a, b)) return 3;
  return 4;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  while (n--) {
    ll s, a, b; cin >> s >> a >> b;
    cout << relation(s, a, b) << " ";
  }
  cout << '\n';
}