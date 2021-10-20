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
  string s;
  cin >> s;
  int A;
  int Z;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s.at(i) == 'A') {
      A = i;
      break;
    }
  }
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    if (s.at(i) == 'Z') {
      Z = i;
      break;
    }
  }
  cout << Z - A + 1 << endl;
}