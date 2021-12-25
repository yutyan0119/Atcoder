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
  string X;
  cin >> X;
  int s = 0, c = 0;
  for (auto nx : X) {
    s += (nx - '0');
  }
  string res;
  for (int i = X.size() - 1;; i--) {
    c += s;
    res.push_back('0' + (c % 10));
    c /= 10;
    if (i >= 0) {
      s -= (X[i] - '0');
    }
    if (i <= 0 && c == 0) {
      break;
    }
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
  return 0;
}