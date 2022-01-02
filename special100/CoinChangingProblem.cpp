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
  int n, m;
  cin >> n >> m;//n円m種類
  vector<int> c(m);
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, n));
  sort(c.begin(), c.end());  // 1を必ず先頭にしておく。
  // dp[i][j]はi-1番目までのコインをつかってj円を実現するときの最少枚数
  for (int i = 0; i < n + 1; i++) {
    dp[1][i] = i;
  }
  for (int i = 0; i < m + 1; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      chmin(dp[i + 1][j], dp[i][j]);
      if (j - c[i] >= 0) {
        chmin(dp[i + 1][j], dp[i][j - c[i]] + 1);
        chmin(dp[i + 1][j], dp[i + 1][j - c[i]] + 1);
      }
    }
  }
  cout << dp[m][n] << endl;
}