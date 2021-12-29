#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

typedef pair<int, int> P;

int wall_x[31][31];
int wall_y[31][31];
int d[31][31];
int main(void) {
  int w, h;
  while (cin >> w >> h && w) {
    rep(i, 31) rep(j, 31) wall_x[i][j] = wall_y[i][j] = -1;
    rep(line, 2 * h - 1) {
      if (line % 2 == 0) {
        rep(i, w - 1) cin >> wall_x[line / 2][i];
      } else {
        rep(i, w) cin >> wall_y[line / 2][i];
      }
    }
    rep(i, 31) rep(j, 31) d[i][j] = 0;
    queue<P> que;
    que.push(P(0, 0));
    d[0][0] = 1;
    while (!que.empty()) {
      P p = que.front();
      que.pop();
      int cy = p.first, cx = p.second;
      if (cy == h - 1 && cx == w - 1) break;

      if (cx > 0 && wall_x[cy][cx - 1] == 0 && d[cy][cx - 1] == 0) {
        d[cy][cx - 1] = d[cy][cx] + 1;
        que.push(P(cy, cx - 1));
      }
      if (cx < w - 1 && wall_x[cy][cx] == 0 && d[cy][cx + 1] == 0) {
        d[cy][cx + 1] = d[cy][cx] + 1;
        que.push(P(cy, cx + 1));
      }
      if (cy > 0 && wall_y[cy - 1][cx] == 0 && d[cy - 1][cx] == 0) {
        d[cy - 1][cx] = d[cy][cx] + 1;
        que.push(P(cy - 1, cx));
      }
      if (cy < h - 1 && wall_y[cy][cx] == 0 && d[cy + 1][cx] == 0) {
        d[cy + 1][cx] = d[cy][cx] + 1;
        que.push(P(cy + 1, cx));
      }
    }
    cout << d[h - 1][w - 1] << endl;
  }
}