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
  int num;
  cin >> num;
  vector<int> ans(num);
  for (int i = 0; i < num; i++) {
    string A, B;
    cin >> A >> B;
    int n = (int)A.size();
    int m = (int)B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 1; j < n + 1; j++) {
      for (int k = 1; k < m + 1; k++) {  // dp[j][k]を更新する
        chmax(dp[j][k], dp[j - 1][k]);
        chmax(dp[j][k], dp[j][k - 1]);
        if (A.at(j - 1) == B.at(k - 1)) {
          chmax(dp[j][k], dp[j - 1][k - 1] + 1);
        }
      }
    }
    ans[i] = dp[n][m];
  }
  for (int i = 0; i < num; i++) {
    cout << ans[i] << endl;
  }
}