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
  int L, R;
  cin >> L >> R;
  string S;
  cin >> S;
  string ans = S;
  for (int i = L - 1, j = 0; i < R; i++, j++) {
    ans.at(i) = S.at(R - 1 - j);
  }
  cout << ans << endl;
}