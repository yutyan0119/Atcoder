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
  int N, W;
  cin >> N >> W;
  vector<int> value(N);
  vector<int> weight(N);
  for (int i = 0; i < N; i++) {
    cin >> value[i] >> weight[i];
  }
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < W + 1; j++) {
      if (j - weight[i] >= 0) {
        chmax(dp.at(i + 1).at(j), dp[i][j - weight[i]] + value[i]);
        chmax(dp[i + 1][j], dp[i + 1][j - weight[i]] + value[i]);
      }
      chmax(dp[i + 1][j], dp[i][j]);
    }
  }
  cout << dp[N][W] << endl;
}