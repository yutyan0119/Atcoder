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
  int dy[4] = {0, 1, 0, -1};
  int dx[4] = {1, 0, -1, 0};
  int R, C;
  cin >> R >> C;
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  sy--;
  sx--;
  gy--;
  gx--;
  vector<vector<char>> field(R, vector<char>(C));
  for (int i = 0; i < R; i++) {
    string S;
    cin >> S;
    for (int j = 0; j < C; j++) {
      field.at(i).at(j) = S.at(j);
    }
  }
  queue<pair<int, int>> que;
  vector<vector<int>> count(R, vector<int>(C, -1));
  que.push({sy, sx});
  count[sy][sx] = 0;
  while (!que.empty()) {
    pair<int, int> pos = que.front();
    que.pop();
    int y = pos.first;
    int x = pos.second;
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (field.at(ny).at(nx) == '#') continue;
      if (count.at(ny).at(nx) != -1) continue;
      count[ny][nx] = count[y][x] + 1;
      que.push({ny, nx});
    }
  }
  cout << count[gy][gx] << endl;
}