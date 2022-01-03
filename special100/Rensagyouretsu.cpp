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
  int n;
  cin >> n;
  vector<int> row(n);
  vector<int> column(n);
  vector<vector<int>> cost(n, vector<int>(n, 0));
  // cost[i][j]はi番目からj番目までの行列の掛け算を前からした時のコスト
  // ex.) cost[0][3] = cost[0][2] + row[3]*row[0]*column[3]; 0,1,2,3
  // ex.) cost[1][4] = cost[1][3] + row[4]*row[1]*column[4]; 1,2,3,4
  for (int i = 0; i < n; i++) {
    cin >> row[i] >> column[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n - 1; j++) {
      cost[i][j + 1] = cost[i][j] + row[j + 1] * row[i] * column[j + 1];
    }
  }
  vector<int> dp(n, INT32_MAX);
  // dp[i]は0からi番目までの行列の掛け算の最少コスト
  // ex.) dp[3] = min(
  //  dp[0] + cost[1][3]+row[0]*column[3]+row[1],
  //  dp[1]+cost[2][3]+row[0]*column[3]*row[2],
  //  dp[2]+cost[3][3]+row[0]*column[3]*row[3]) 0,1,2,3
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if(chmin(dp[i], dp[j] + cost[j + 1][i] + row[0] * column[i] * row[j + 1])){
        cout << i << " " << j << endl;
      }
    }
  }
  cout << dp[n-1] << endl;
}