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
  long long A, B, C, K;
  cin >> A >> B >> C >> K;
  if (abs(A - B) > pow(10, 18))
    cout << "Unfair" << endl;
  else if (K % 2 == 0)
    cout << A - B << endl;
  else
    cout << B - A << endl;
}