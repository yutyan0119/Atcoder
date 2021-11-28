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
  string S1, S2;
  cin >> S1 >> S2;
  int count = 0;
  for (int i = 0; i < 2; i++) {
    if (S1.at(i) == '#') {
      count++;
    }
  }
  for (int i = 0; i < 2; i++) {
    if (S2.at(i) == '#') {
      count++;
    }
  }
  if (count >= 3){
    cout << "Yes" << endl;
    return 0;
  }
  if (count == 2){
    if ((S1.at(0) =='#'&& S2.at(1) == '#') || (S1.at(1)=='#' &&S2.at(0)=='#')){
      cout << "No" << endl;
    }else {
      cout << "Yes" << endl;
    }
  }
}