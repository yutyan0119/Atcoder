#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T& a, T b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T& a, T b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for (int i = s; i < e; i++)
const int INF = 1 << 30;
/* ---------------------------------------------------*/

int main() {
  int N;
  cin >> N;
  int h[N];
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  vector <int> dp(N,INF);  //足場iにたどり着くまでの最小コスト
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  for (int i = 2; i < N; i++) {
    chmin(dp[i],(dp[i - 1] + abs(h[i] - h[i - 1])));
    chmin(dp[i],(dp[i - 2] + abs(h[i] - h[i - 2])));
  }
  cout << dp[N-1] << endl;
}