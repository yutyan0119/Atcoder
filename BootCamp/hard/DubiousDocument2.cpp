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

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  string Sf, T, ans;
  cin >> Sf >> T;
  int n = (int)Sf.size();
  int m = (int)T.size();
  bool exist = false;
  for (int i = n - 1; i >= 0; i--) {
    bool can = true;
    for (int j = 0; j < m; j++) {
      if (Sf.at(i - m + 1 + j) != '?' && Sf.at(i - m + 1 + j) != T.at(j)) {
        can = false;
      }
    }
    if (can) {
      string S = Sf;
      for (int j = i - m + 1; j <= i; j++) {
        S.at(j) = T.at(j - (i - m + 1));
      }
      for (int j = 0; j < n; j++) {
        if (S.at(j) == '?') {
          S.at(j) = 'a';
        }
      }
      cout << S << endl;
      exist = true;
      break;
    }
  }
  if (!exist) {
    cout << "UNRESTORABLE" << endl;
  }
  return 0;
}