#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "header.hpp"
#include "data_structure/fenwick.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e5 + 3;

int x[MX], y[MX], cntx, cnty;

void solve() {
  int r, c, q; cin >> r >> c >> q;
  map<int, int> mx, my, rx, ry;
  rep(i, 1, q) {
    cin >> x[i] >> y[i];
    mx[x[i]] = 1; my[y[i]] = 1;
  }
  cntx = 0; for (auto [i, j] : mx) mx[i] = ++cntx, rx[cntx] = i;
  cnty = 0; for (auto [i, j] : my) my[i] = ++cnty, ry[cnty] = i;

  fenwick<int> rangeR(cnty+1), rangeC(cntx+1), existR(cntx+1), existC(cnty+1);
  vector<multiset<int>> R(cntx+1), C(cnty+1);
  multiset<int> gR, gC;
  map<pii, bool> seen;
  ll cntR = 0, cntC = 0;
  ll ans = 0;
  rep(i, 1, q) {
    int xx = mx[x[i]], yy = my[y[i]];
    //remove pawn
    if (seen[{xx, yy}]) {
      seen[{xx, yy}] = 0;

      //empty col
      C[yy].erase(C[yy].find(xx));
      if (C[yy].empty()) {
        cntC--;
        rangeC.update(xx, xx, -1);
        ans -= r - existR.query(1, cntx);
      }
      //not empty col
      else {
        int mn = *C[yy].begin(), mx = *C[yy].rbegin();
        //change prefix
        if (xx < mn) {
          rangeC.update(xx, mn-1, -1);
          ans += rx[mn] - rx[xx] - existR.query(xx, mn-1);
        }
        //change suffix
        else if (xx > mx) {
          rangeC.update(mx+1, xx, -1);
          ans += rx[xx] - rx[mx] - existR.query(mx+1, xx);
        }
      }
      gR.erase(gR.find(xx));
      if (gR.count(xx) == 0) {
        existR.update(xx, -1);
        ans += cntC - rangeC.query(xx);
      }

      //empty row
      R[xx].erase(R[xx].find(yy));
      if (R[xx].empty()) {
        cntR--;
        rangeR.update(yy, yy, -1);
        ans -= c - existC.query(1, cnty);
      }
      //not empty col
      else {
        int mn = *R[xx].begin(), mx = *R[xx].rbegin();
        //change prefix
        if (yy < mn) {
          rangeR.update(yy, mn-1, -1);
          ans += ry[mn] - ry[yy] - existC.query(yy, mn-1);
        }
        //change suffix
        else if (yy > mx) {
          rangeR.update(mx+1, yy, -1);
          ans += ry[yy] - ry[mx] - existC.query(mx+1, yy);
        }
      }
      gC.erase(gC.find(yy));
      if (gC.count(yy) == 0) {
        existC.update(yy, -1);
        ans += cntR - rangeR.query(yy);
      }
    }
    //place pawn
    else {
      seen[{xx, yy}] = 1;

      if (gR.count(xx) == 0) {
        existR.update(xx, 1);
        ans -= cntC - rangeC.query(xx);
      }
      gR.insert(xx);

      //empty col
      if (C[yy].empty()) {
        C[yy].insert(xx);
        cntC++;
        rangeC.update(xx, xx, 1);
        ans += r - existR.query(1, cntx);
      }
      //not empty col
      else {
        int mn = *C[yy].begin(), mx = *C[yy].rbegin();
        C[yy].insert(xx);
        //change prefix
        if (xx < mn) {
          rangeC.update(xx, mn-1, 1);
          ans -= rx[mn] - rx[xx] - existR.query(xx, mn-1);
        }
        //change suffix
        else if (xx > mx) {
          rangeC.update(mx+1, xx, 1);
          ans -= rx[xx] - rx[mx] - existR.query(mx+1, xx);
        } 
      }

      if (gC.count(yy) == 0) {
        existC.update(yy, 1);
        ans -= cntR - rangeR.query(yy);
      }
      gC.insert(yy);

      //empty row
      if (R[xx].empty()) {
        R[xx].insert(yy);
        cntR++;
        rangeR.update(yy, yy, 1);
        ans += c - existC.query(1, cnty);
      }
      //not empty row
      else {
        int mn = *R[xx].begin(), mx = *R[xx].rbegin();
        R[xx].insert(yy);
        //change prefix
        if (yy < mn) {
          rangeR.update(yy, mn-1, 1);
          ans -= ry[mn] - ry[yy] - existC.query(yy, mn-1);
        }
        //change suffix
        else if (yy > mx) {
          rangeR.update(mx+1, yy, 1);
          ans -= ry[yy] - ry[mx] - existC.query(mx+1, yy);
        } 
      }
    }
    cout << ans << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}