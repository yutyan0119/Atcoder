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
  string S;
  cin >> S;
  int N = S.size();
  bool yes = true;
  for (int i = 0; i < N - 1; i++) {
    if (S.at(i) == 'o') {
      if (i + 1 < N) {
        if (S.at(i+1) != 'x') {
          yes = false;
          break;
        }
      }
    }
    if (S.at(i) == 'x') {
      if (i == 0) {
        continue;
      } else if (S.at(i - 1) == 'x') {
        if (i + 1 < N && S.at(i + 1) != 'o') {
          yes = false;
          break;
        }
      } else if (S.at(i - 1) == 'o') {
        if (i + 1 < N && S.at(i + 1) != 'x') {
          yes = false;
          break;
        }
      }
    }
  }
  cout << ((yes) ? "Yes" : "No") << endl;
}