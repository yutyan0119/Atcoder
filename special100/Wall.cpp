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

#define INF 1e10

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<ll>> dp(10, vector<ll>(10, INF));
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> dp[i][j];
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        chmin(dp[j][k], dp[j][i] + dp[i][k]);
      }
    }
  }
  vector<vector<int>> A(H, vector<int>(W));
  ll ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      if (A[i][j] == -1) continue;
      ans += dp[A[i][j]][1];
    }
  }
  cout << ans << endl;
}