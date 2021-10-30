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
  int N, M;
  cin >> N >> M;
  vector<vector<long long>> b(N, vector<long long>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> b[i][j];
    }
  }
  bool can = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M - 1; j++) {
      if (b[i][j] != b[i][j + 1] - 1) {
        can = false;
        break;
      }
      if (b[i][j] % 7 == 0 && j != M - 1) {
        can = false;
        break;
      }
    }
    if (i < N - 1) {
      if (b[i][0] + 7 != b[i + 1][0]) {
        can = false;
        break;
      }
    }
  }
  cout << ((can) ? "Yes" : "No") << endl;
}