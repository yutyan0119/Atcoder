#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for (int i = s; i < e; i++)

/* ---------------------------------------------------*/

int main() {
  int N, D, count = 0;
  cin >> N >> D;
  int X[N][D];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> X[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double sum = 0;
      for (int k = 0; k < D; k++) {
        sum += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
      }
      int sumsqrt = (int)sqrt(sum);
      if (sumsqrt * sumsqrt == sum) count++;
    }
  }
  cout << count << endl;
}