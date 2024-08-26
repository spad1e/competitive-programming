/*
Matrix Data Structure for Matrix Operations and Matrix Exponentiation
Modified from : https://github.com/ShahjalalShohag/code-library/blob/main/Math/Matrix%20Exponentiation.cpp
verification : 
  https://programming.in.th/submissions/193326
  https://codeforces.com/gym/102644/submission/270128255
*/

#pragma once
#include "header.hpp"

template<class T>
struct Matrix {
  int n, m;
  vector<vector<T>> M;
  Matrix() {}
  Matrix(int _n, int _m) {n=_n; m=_m; M.assign(n, vector<T>(m, T{}));}
  Matrix(vector<vector<T>> a) {n=a.size(); m=n?a[0].size():0; M=a;}
  static inline Matrix<T> identity(int n) {
    Matrix ans = Matrix(n, n);
    for (int i = 0; i < n; ++i) ans[i][i] = 1;
    return ans;
  }

  inline Matrix operator + (const Matrix &other) {
    assert(n==other.n && m==other.m);
    Matrix ans = Matrix(n, m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] += M[i][j] + other[i][j];
    return ans;
  }

  inline Matrix operator - (const Matrix &other) {
    assert(n==other.n && m==other.m);
    Matrix ans = Matrix(n, m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] -= M[i][j] + other[i][j];
    return ans;
  }

  inline Matrix operator % (const int MOD) {
    Matrix ans = Matrix(n, m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) ans[i][j] = M[i][j] % MOD;
    return ans;
  }

  inline Matrix operator * (const Matrix &other) {
    assert(m == other.n);
    Matrix ans = Matrix(n, other.m);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < other.m; ++k) ans[i][k] += M[i][j]*other[j][k];
    return ans; 
  }

  inline Matrix operator = (const vector<vector<T>> v) {
    n = v.size();
    m = (n > 0) ? v[0].size() : 0;
    M = v;
    return *this;
  }

  inline Matrix pow(long long b) {
    assert(n==m);
    Matrix a(M);
    Matrix res = Matrix<T>::identity(n);
    for (;b>0;b >>= 1, a*=a) if (b&1) res *= a;
    return res;
  }

  inline vector<T>& operator [] (const int i) {
    return M[i];
  }

  const inline vector<T>& operator [] (const int i) const {
    return M[i];
  }

  inline Matrix& operator += (const Matrix& other) {return *this = (*this) + other;}
  inline Matrix& operator -= (const Matrix& other) {return *this = (*this) - other;}
  inline Matrix& operator *= (const Matrix& other) {return *this = (*this) * other;}
  inline bool operator == (const Matrix& other) {return M == other.M;}
  inline bool operator != (const Matrix& other) {return M != other.M;}
};