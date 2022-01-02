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
  vector<pair<int, int>> v(N);
  for (int i = 0; i < N; i++) {
    int V, w;
    cin >> V >> w;
    v[i].first = V;
    v[i].second = w;
  }
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j - v[i].second >= 0) {
        chmax(dp[i + 1][j], dp[i][j - v[i].second] + v[i].first);
      }
      chmax(dp[i + 1][j], dp[i][j]);
    }
  }
  cout << dp[N][W] << endl;
}