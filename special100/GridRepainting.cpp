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
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int H, W;
  cin >> H >> W;
  int kabe = 0;
  vector<vector<int>> field(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char a;
      cin >> a;
      if (a == '.') {
        field[i][j] = 0;
      } else {
        field[i][j] = 1;  //壁
        kabe++;
      }
    }
  }
  vector<vector<int>> path(H, vector<int>(W, -1));
  queue<pair<int, int>> Q;
  Q.push({0, 0});
  path[0][0] = 1;
  while (!Q.empty()) {
    int y = Q.front().first;
    int x = Q.front().second;
    Q.pop();
    if (field[y][x] == 1) {
      continue;
    }
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (0 <= ny && ny < H && 0 <= nx && nx < W && path[ny][nx] == -1) {
        path[ny][nx] = path[y][x] + 1;
        Q.push({ny, nx});
      }
    }
  }
  if (path[H - 1][W - 1] == -1)
    cout << -1 << endl;
  else
    cout << H * W - kabe - path[H - 1][W - 1] << endl;
}