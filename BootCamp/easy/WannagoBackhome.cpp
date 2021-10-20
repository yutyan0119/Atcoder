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
  int ncount = 0;
  int scount = 0;
  int ecount = 0;
  int wcount = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    if (S.at(i) == 'N') ncount++;
    if (S.at(i) == 'S') scount++;
    if (S.at(i) == 'E') ecount++;
    if (S.at(i) == 'W') wcount++;
  }
  if ((ncount == 0 || scount == 0) && !(ncount == 0 && scount == 0)) {
    cout << "No" << endl;
  } else if ((wcount == 0 || ecount == 0) && !(wcount == 0 && ecount == 0)) {
    cout << "No" << endl;
  } else
    cout << "Yes" << endl;
}