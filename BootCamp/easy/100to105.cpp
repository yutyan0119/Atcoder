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
  int t = x % 100;
  int n = 0;
  int d = 5;
  for (int i = 0; i < 100; i++) {
    if (t / d != 0) {
      t -= d;
      ++n;
    } else if (t / d == 0 && t != 0) {
      --d;
    }
    if (t == 0) break;
  }
  if (100 * n > x) {
    cout << 0 << endl;
  } else
    cout << 1 << endl;
}