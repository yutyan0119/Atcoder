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
int m, n;
vector<vector<int>> field;
int maxcount = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dfs(vector<vector<int>> G, int y, int x, int count) {
  G[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (G[ny][nx] == 1) {
      dfs(G, ny, nx, count + 1);
    }
  }
  G[y][x] = 1;
  if (!(G[y + 1][x] || G[y][x + 1] || G[y - 1][x] || G[y][x - 1])) {
    chmax(maxcount, count);
    return;
  }
}

int main() {
  cin >> m >> n;
  field.assign(n + 2, vector<int>(m + 2, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> field[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int count = 1;
      if (field[i][j] == 0) continue;
      dfs(field, i, j, count);
      chmax(maxcount, count);
    }
  }
  cout << maxcount << endl;
}