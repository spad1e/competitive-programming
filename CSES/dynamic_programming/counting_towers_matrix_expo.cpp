#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

template <class T>
struct Matrix {
  int n, m;
  vector<vector<T>> a;
  Matrix(vector<vector<T>> M) {
    a = M; n = a.size(), m = a[0].size();
  }
  static Matrix identity(int n) {
    Matrix ret = vector<vector<T>>(n, vector<T>(n, 0));
    for (int i = 0; i < n; ++i) ret[i][i] = 1;
    return ret;
  }
  static Matrix zero(int n, int m) {
    return vector<vector<T>>(n, vector<T>(m, 0));
  }
  friend Matrix operator*(Matrix &a, Matrix &b) {
    assert(a.m == b.n);
    Matrix ret = Matrix<T>::zero(a.m, b.n);
    for (int i = 0; i < a.n; ++i) for (int j = 0; j < b.m; ++j) for (int k = 0; k < a.m; ++k) {
      ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
    }
    return ret;
  }
  vector<T>& operator[](int index) {
    return a[index];
  }
};

template <class T>
Matrix<T> binpow(Matrix<T> a, ll b) {
  Matrix<T> ret = Matrix<T>::identity(2);
  for (; b; b>>=1, a=a*a) if (b&1) ret=ret*a;
  return ret;
}

void solve() {
  int n; cin >> n;
  Matrix<ll> m({{2, 1}, {1, 4}});
  Matrix<ll> res = binpow(m, n-1);
  cout << (res[0][0] + res[0][1] + res[1][0] + res[1][1]) % MOD << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}
