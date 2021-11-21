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
  int S, T, X;
  cin >> S >> T >> X;
  if (S < T) {
    if (S <= X && X < T) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else if (T < S) {
    if (0 <= X && X <= T) {
      X += 24;
    }
    T += 24;
    if (S <= X && X < T) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "Yes" << endl;
  }
}