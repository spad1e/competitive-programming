#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

struct Node {
  ll sum, cnt;
  Node *lc, *rc;
  Node() {
    sum = cnt = 0;
    lc = rc = nullptr; 
  }
  void createChild() {
    if (lc == nullptr) lc = new Node();
    if (rc == nullptr) rc = new Node();
  }
};

Node *root = new Node();

void update(ll l, ll r, ll x, ll val, Node *cur) {
  if (l==r) {
    cur -> cnt += val;
    cur -> sum += x*val;
    return;
  }
  ll mid = (l+r)>>1;
  cur -> createChild();
  if (x <= mid) update(l, mid, x, val, cur -> lc);
  else update(mid+1, r, x, val, cur -> rc);

  cur->sum = cur->lc->sum + cur->rc->sum;
  cur->cnt = cur->lc->cnt + cur->rc->cnt;
}

ll search(ll l, ll r, ll lsum, ll rfreq, ll k, Node *cur) {
  if (l==r) return l;
  ll mid = (l+r)>>1;
  cur -> createChild();
  __int128_t cntMid = lsum + (__int128_t)(mid+1)*rfreq + (cur->lc->sum) + (__int128_t)(mid+1)*(cur->rc->cnt);
  if (cntMid < (__int128_t)(mid+1)*k) return search(l, mid, lsum, rfreq + cur->rc->cnt, k, cur -> lc);
  else return search(mid+1, r, lsum + cur->lc->sum, rfreq, k, cur -> rc);
}

ll a[MX];

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> a[i], update(1, 1e15, a[i], 1, root);
  ll answer = 0;
  int q; cin >> q;
  while (q--) {
    int x, y; cin >> x >> y;
    x = (x^answer) % n + 1;
    update(1, 1e15, a[x], -1, root);
    update(1, 1e15, a[x]+=y, 1, root);
    answer = search(1, 1e15, 0, 0, k, root);
    cout << answer << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}