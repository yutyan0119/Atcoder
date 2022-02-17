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
  int K, S;
  cin >> K >> S;
  ll count = 0;
  /* i<=j<=kでやってみたい*/
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j <= K; j++) {
      int k = S - i - j;
      if (0 <= k and k <= K) {
        count++;
      }
    }
  }
  cout << count << endl;
}
