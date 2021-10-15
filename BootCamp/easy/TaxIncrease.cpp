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
  int A, B;
  cin >> A >> B;
  int i = 0;
  while (true) {
    if (A == (int)(i * 0.08) && B == (int)(i * 0.1)) {
      cout << i << endl;
      return 0;
    }
    if (A < (int)(i * 0.08) || B < (int)(i * 0.1)) {
      cout << -1 << endl;
      break;
    }
    ++i;
  }
}