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
  string S;
  cin >> S;
  int N = (int)S.size();
  bool can = true;
  bool acan = true;
  int j = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(N - 1 - i) != 'a') {
      acan = false;
    }
    if (S.at(j) != S.at(N - 1 - i)) {
      if (S.at(N - 1 - i) == 'a' && acan) {
        continue;
      }
      can = false;
      break;
    }
    j++;
  }
  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}