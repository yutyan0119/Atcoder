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

int H, W;

bool xmove(vector<vector<char>>& C, int x, int y) {
  if (x + 1 >= W)
    return false;
  else {
    if (C[y][x + 1] != '#') return true;
  }
  return false;
}

bool ymove(vector<vector<char>>& C, int x, int y) {
  if (y + 1 >= H)
    return false;
  else {
    if (C[y + 1][x] != '#') return true;
  }
  return false;
}

//これはD問題です
int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  cin >> H >> W;
  vector<vector<char>> C(H, vector<char>(W));
  vector<vector<int>> map(H, vector<int>(W, -1));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> C[i][j];
    }
  }
  map[0][0] = 0;
  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (map[i][j] != -1) {
        if (xmove(C, j, i)) {
          chmax(map[i][j + 1], map[i][j] + 1);
          chmax(ans, map[i][j + 1]);
        }
        if (ymove(C, j, i)) {
          chmax(map[i + 1][j], map[i][j] + 1);
          chmax(ans, map[i + 1][j]);
        }
      }
    }
  }
  cout << ans + 1 << endl;
}