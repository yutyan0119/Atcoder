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
  int N;
  cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  vector<vector<bool>> E(N, vector<bool>(N, true));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (A[i][j] > A[i][k] + A[k][j]) {
          cout << "-1" << endl;
          return 0;
        }
        if (i == j || j == k || i == k) continue;
        if (A[i][j] == A[i][k] + A[k][j]) {
          // cout << i << j << k << endl;
          E[i][j] = false;
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // cout << E[i][j] * A[i][j] << " ";
      ans += E[i][j] * A[i][j];
    }
    // cout << "\n";
  }
  cout << ans / 2 << endl;
}