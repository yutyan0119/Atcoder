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
const int INF = 1000000000;
/* ---------------------------------------------------*/

int main() {
  int N;
  int K;
  cin >> N >> K;
  int h[N];
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  vector<int> dp(N, INF);  //足場iにたどり着くのに必要なコスト
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= K; j++) {
      if (i + j < N) chmin(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
    }
  }
  cout << dp[N-1] << endl;
}