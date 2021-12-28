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
  int dy[6] = {-1, -1, 0, 1, 1, 0};
  int dx1[6] = {0, 1, 1, 1, 0, -1};
  int dx2[6] = {-1, 0, 1, 0, -1, -1};
  int W, H;
  cin >> W >> H;
  vector<vector<int>> JOI(H + 2, vector<int>(W + 2, 0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> JOI[i + 1][j + 1];
    }
  }
  int count = 0;
  queue<pair<int, int>> que;
  que.push({0, 0});
  while (!que.empty()) {
    int x = que.front().second;
    int y = que.front().first;
    que.pop();
    if (JOI[y][x] != -1) {
      JOI[y][x] = -1;  //探索済み
    } else {
      continue;
    }
    for (int i = 0; i < 6; i++) {
      int ny;
      int nx;
      if (y % 2) {
        ny = y + dy[i];
        nx = x + dx1[i];
      } else {
        ny = y + dy[i];
        nx = x + dx2[i];
      }
      if (0 <= nx && nx < W + 2 && 0 <= ny && ny < H + 2) {
        if (JOI[ny][nx] == 1) {
          count++;
        } else if (JOI[ny][nx] == 0) {
          que.push({ny, nx});
        }
      }
    }
  }
  cout << count << endl;
}