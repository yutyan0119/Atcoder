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
  int x;
  cin >> x;
  double xs = sqrt(x);
  int def = x;
  if (x == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 2; i < xs; i++) {
    for (int j = 1; pow(i, j) <= x; j++) {
      chmin(def, x - (int)pow(i, j));
    }
  }
  cout << x - def << endl;
}