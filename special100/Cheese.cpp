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
  int H, W, N;
  cin >> H >> W >> N;
  int sy, sx;
  vector<vector<char>> field(H + 2, vector<char>(W + 2, 'X'));
  for (int i = 0; i < H; i++) {
    string S;
    cin >> S;
    for (int j = 0; j < W; j++) {
      field[i + 1][j + 1] = S.at(j);
      if (S.at(j) == 'S') {
        sy = i + 1;
        sx = j + 1;
      }
    }
  }
  int tekazu = 0;
  for (int i = 1; i <= N; i++) {
    queue<pair<int, int>> vec;
    vec.push({sy, sx});
    vector<vector<int>> count(H + 2, vector<int>(W + 2, -1));
    count[sy][sx] = 0;
    while (!vec.empty()) {
      bool find = false;
      pair<int, int> svec = vec.front();
      vec.pop();
      int y = svec.first;
      int x = svec.second;
      for (int j = 0; j < 4; j++) {
        int ny = y + dy[j];
        int nx = x + dx[j];
        if (field[ny][nx] == 'X') continue;
        if (count[ny][nx] != -1) continue;
        count[ny][nx] = count[y][x] + 1;
        vec.push({ny, nx});
        if (field[ny][nx] == i + '0') {
          sy = ny;
          sx = nx;
          find = true;
          break;
        }
      }
      if (find) break;
    }
    tekazu += count[sy][sx];
  }
  cout << tekazu << endl;
}