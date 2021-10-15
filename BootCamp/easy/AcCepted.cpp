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
  string S;
  cin >> S;
  if (S.at(0) != 'A') {
    cout << "WA" << endl;
    return 0;
  }
  int Ccount = 0;
  int Cindex = 0;
  for (int i = 2; i < S.size() - 1; i++) {
    if (S.at(i) == 'C') {
      Ccount++;
      Cindex = i;
    }
  }
  if (Ccount != 1) {
    cout << "WA" << endl;
    return 0;
  }
  for (int i = 1; i < S.size(); i++) {
    if (i == Cindex) {
      continue;
    } else if (S.at(i) - 'a' < 0) {
      cout << "WA" << endl;
      return 0;
    }
  }
  cout << "AC" << endl;
}