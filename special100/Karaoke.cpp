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
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> A(N, vector<ll>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  ll ans = 0;
  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j < M; j++) {
      ll sum = 0;
      for (int k = 0; k < N; k++) {
        ll score;
        score = max(A[k][i], A[k][j]);
        sum += score;
      }
      chmax(ans, sum);
    }
  }
  cout << ans << endl;
}