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
  string O, E;
  cin >> O >> E;
  for (int i = 0; i < (int)O.size(); ++i) {
    cout << O.at(i);
    if (!(i == (int)O.size() - 1 && O.size() > E.size())) {
      cout << E.at(i);
    }
  }
  cout << endl;
}