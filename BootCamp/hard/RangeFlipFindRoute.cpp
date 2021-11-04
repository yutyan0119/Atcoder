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
  int H, W;
  cin >> H >> W;
  char s[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> s[i][j];
    }
  }
  vector<int> dx = {1, 0};
  vector<int> dy = {0, 1};
  ll INF = 1LL<<60;

  vector<vector<long long>> dp(H, vector<long long>(W, INF));  // dp[i][j]は(j,i)に到達するのに必要な塗り替えの最小回数
  
  dp[0][0] = (s[0][0] == '.' ? 0 : 1);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      for (int dir = 0; dir < 2; ++dir) {
        int ni = i + dx[dir], nj = j + dy[dir]; // 変位(1,0)または(0,1)
        if (ni >= H || nj >= W) continue;
        int add = 0;
        if (s[ni][nj] == '#' && s[i][j] == '.') add = 1;
        chmin(dp[ni][nj], dp[i][j] + add);
      }
    }
  }
  cout << dp[H - 1][W - 1] << endl;
}