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
  int a[N];
  int b[N];
  int MOD = 998244353;
  rep(i, 0, N) { cin >> a[i]; }
  rep(i, 0, N) { cin >> b[i]; }
  vector<vector<ll>> dp(
      N, vector<ll>(3000, 0));  // i番目でjを選んだときのi番目の通り
  vector <ll> Rui(3000,0); //i-1番目のパターンの累積和
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3000; j++) {
      if (i == 0 && j <= b[i] && a[i] <= j) {
        dp[i][j] = 1;
      } else if (j <= b[i] && a[i] <=j) {
          dp[i][j] = Rui[j];
          dp[i][j]%=MOD;
          printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
        }
      if (j == 0) Rui[j] = dp[i][j];
      else Rui[j] = Rui[j-1] + dp[i][j];
    }
  }
  ll sum = 0;
  for (int i = 0; i < 3000; i++) {
    sum += dp[N - 1][i];
  }
  cout << sum%MOD << endl;
}