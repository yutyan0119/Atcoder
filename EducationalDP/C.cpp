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
const int INF = 100000000;

/* ---------------------------------------------------*/

int main() {
  int N;
  cin >> N;
  int a[N], b[N], c[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<int>> dp(
      N, vector<int>(3,0));  // i日目にjを選んで選んで得られる幸福度の総和の最大値
  dp[0] = {a[0], b[0], c[0]};
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        chmax(dp[i][j], dp[i - 1][1] + a[i]);
        chmax(dp[i][j], dp[i - 1][2] + a[i]);
      }
      if (j == 1) {
        chmax(dp[i][j], dp[i - 1][0] + b[i]);
        chmax(dp[i][j], dp[i - 1][2] + b[i]);
      }
      if (j == 2) {
        chmax(dp[i][j], dp[i - 1][1] + c[i]);
        chmax(dp[i][j], dp[i - 1][0] + c[i]);
      }
    }
  }
  cout << max(dp.at(N-1).at(0),max(dp.at(N-1).at(1),dp.at(N-1).at(2))) << endl;
}