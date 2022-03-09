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

const ll mod = 998244353;

int main() {
  ll N;
  cin >> N;
  vector<vector<ll>> dp(N, vector<ll>(9, 0));
  for (int i = 0; i < 9; i++) {
    dp[0][i] = 1;
  }
  for (ll i = 0; i < N - 1; i++) {
    for (int j = 0; j < 9; j++) {
      if (j == 0) {
        dp[i + 1][j] = dp[i][j] + dp[i][j + 1];
      } else if (j == 8) {
        dp[i + 1][j] = dp[i][j] + dp[i][j - 1];
      } else {
        dp[i + 1][j] = dp[i][j] + dp[i][j - 1] + dp[i][j + 1];
      }
      dp[i + 1][j] %= mod;
    }
  }
  ll ans = 0;
  for (ll i = 0; i < 9; i++) {
    ans += dp[N - 1][i];
    ans %= mod;
  }
  cout << ans << endl;
}
