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
  int N = S.size() + 1;
  vector<int> A(N, 0);
  for (int i = 0; i < N - 1; i++) {
    if (S[i] == '<') chmax(A[i + 1], A[i] + 1);
  }
  for (int i = N - 2; i >= 0; i--) {
    if (S[i] == '>') chmax(A[i], A[i + 1] + 1);
  }
  ll res = 0;
  for (int i = 0; i < N; i++) {
    res += A[i];
  }
  cout << res << endl;
}