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
  int A, B, C;
  cin >> A >> B >> C;
  A = A % B;
  for (int i = 1; i <= B; i++) {
    int D = (A * i) % B;
    if (D == C) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}