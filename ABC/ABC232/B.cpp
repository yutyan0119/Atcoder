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

#define rep(i1, s, e) for (int i1 = s; i1 < e; i1++)

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  string S, T;
  cin >> S >> T;
  int N = T.size();
  for (int i = 1; i < 28; i++) {
    for (int j = 0; j < N; j++) {
      T.at(j) = T.at(j) + 1;
      if (T.at(j)-'a' >= 26) {
        T.at(j) -= 26;
      }
    }
    // cout << T << endl;
    if (S == T) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}