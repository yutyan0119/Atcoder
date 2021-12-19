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

// bool canmove(vector<vector<char>> C, int H, int W, int x, int y) {
//   if (x + 1 >= W || y + 1 >= H) {
//     return false;
//   }
//   if (C.at(y + 1).at(x) == '#' && C.at(y).at(x + 1) == '#') {
//     return false;
//   }
//   return true;
// }
int maxmove(int i, int j, int count, vector<vector<char>> C, int H, int W) {
  if (C.at(i).at(j) == '#') {
    return count;
  }
  count++;
  if (j + 1 >= W || i + 1 >= H) {
    if (i + 1 == H && j + 1 == W) {
      return count;
    }
    if (j + 1 == W) {
      return maxmove(i + 1, j, count, C, H, W);
    }
    if (i + 1 == H) {
      return maxmove(i, j + 1, count, C, H, W);
    }
    return count;
  }
  if (C[i + 1][j] == '#' && C[i][j + 1] == '#') {
    return count;
  }
  return max(maxmove(i + 1, j, count, C, H, W),
             maxmove(i, j + 1, count, C, H, W));
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> C(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> C[i][j];
    }
  }
  int ans = 0;
  cout << maxmove(0, 0, ans, C, H, W) << endl;
}