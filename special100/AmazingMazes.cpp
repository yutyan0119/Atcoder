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
  int w, h;
  while (cin >> w >> h) {
    if (w == 0 && h == 0) break;
    int ans;
    vector<vector<int>> field(62, vector<int>(62, 1));
    for (int i = 0; i < h * 2 - 1; i++) {
      for (int j = 0; j < w * 2 - 1; j++) {
        field[i + 1][j + 1] = 0;
      }
    }
    for (int i = 0; i < h * 2 - 1; i++) {
      if (i % 2 == 0) {
        for (int j = 0; j < w - 1; j++) {
          int a;
          cin >> a;
          field[i][2 * j + 2] |= a;
          field[i + 1][2 * j + 2] |= a;
          field[i + 2][2 * j + 2] |= a;
        }
      } else {
        for (int j = 0; j < w; j++) {
          int a;
          cin >> a;
          field[i + 1][j * 2] |= a;
          field[i + 1][j * 2 + 1] |= a;
          field[i + 1][j * 2 + 2] |= a;
        }
      }
    }
    queue<pair<int, int>> Q;
    Q.push({1, 1});
    vector<vector<int>> count(2 * h - 1, vector<int>(2 * w - 1, 0));
    while (!Q.empty()) {
      int y = Q.front().first;
      int x = Q.front().second;
      if (field[y][x] == -1)
        continue;
      else {
        field[y][x] = -1;
      }
      if (x == w * 2 - 1 && y == h * 2 - 1) {
        ans = count[y][x] / 2 + 1;
        break;
      }
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        count[ny][nx] = count[y][x] + 1;
        Q.push({ny, nx});
      }
    }
    cout << ans << endl;
  }
}
