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
  int dy[6] = {-1, -1, 0, 0, 1, 1};
  int dx[6] = {0, 1, -1, 1, 0, 1};
  int W, H;
  cin >> W >> H;
  vector<vector<int>> JOI(H + 2, vector<int>(W + 2, 0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> JOI[i + 1][j + 1];
    }
  }
  int count = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (JOI[i][j] == 1) {
        int ijcount = 6;
        for (int k = 0; k < 6; k++) {
          if (JOI[i + dy[k]][i + dx[k]] == 1) {
            ijcount--;
          }
        }
        count += ijcount;
      }
    }
  }
  cout << count << endl;
}