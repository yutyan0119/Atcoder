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
  string S;
  cin >> S;
  int N = (int)S.size();
  vector<vector<int>> dp(N + 1, vector<int>(3, -1));
  dp[0][0] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= min(i, 2); ++j) {
      string suffix = S.substr(i - j, j);
      for (int add = 1; add <= 2 && i + add <= N; ++add) {
        // 同じものが連続しないなら更新
        if (S.substr(i, add) != suffix) {
          chmax(dp[i + add][add], dp[i][j] + 1);
        }
      }
    }
  }
  cout << max(dp[N][1], dp[N][2]) << endl;
}