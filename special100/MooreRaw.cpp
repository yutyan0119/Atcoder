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

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  double P;  //今だとP年かかる
  cin >> P;
  double x;
  x = 3 * log(2 * P * log(2.0) / 3) / 2;
  double y = 2 * x / 3;
  if (x <= 0) {
    cout << P << endl;
  } else {
    cout << x + P / (pow(2.0, y)) << endl;
  }
}