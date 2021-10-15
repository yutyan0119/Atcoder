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
  int N;
  cin >> N;
  int B[N - 1];
  int A[N];
  for (int i = 0; i < N - 1; i++) {
    cin >> B[i];
  }
  A[0] = B[0];
  for (int i = 0; i < N - 1; i++) {
    if (B[i] <= A[i]) A[i] = B[i];
    A[i + 1] = B[i];
  }
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
  }
  cout << sum << endl;
}