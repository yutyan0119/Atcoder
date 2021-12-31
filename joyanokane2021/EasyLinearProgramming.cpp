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
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  if (A >= K) {
    cout << K << endl;
  } else if (A + B >= K) {
    cout << A << endl;
  } else {
    cout << A - (K - (A + B)) << endl;
  }
}