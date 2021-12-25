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

int w, h;
vector<vector<int>> field;

void dfs(int y, int x) {
  field[y][x] = 0;
  for (int dy = -1; dy <= 1; dy++) {
    for (int dx = -1; dx <= 1; dx++) {
      int ny = y + dy;
      int nx = x + dx;
      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if (field[ny][nx] == 0) continue;
      dfs(ny, nx);
    }
  }
}

int main() {
  vector<int> countarray;
  while (cin >> w >> h) {
    if (h == 0 || w == 0) break;
    field.assign(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> field[i][j];
      }
    }
    int count = 0;
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        if (field[y][x] == 0) continue;
        dfs(y, x);
        ++count;
      }
    }
    countarray.push_back(count);
  }
  for (int i = 0; i < (int)countarray.size(); i++) {
    cout << countarray[i] << endl;
  }
}