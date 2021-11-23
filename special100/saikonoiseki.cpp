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

bool in(int x) {
  if (0 <= x && x <= 5000) {
    return true;
  } else {
    return false;
  }
}
bool in2(int x, int y, int z, int w) {
  if (in(x) && in(y) && in(z) && in(w)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int N;
  cin >> N;
  if (N <= 3) {
    cout << 0 << endl;
    return 0;
  }
  vector<pair<int, int>> point(N);
  vector<vector<bool>> exist(5010, vector<bool>(5010, false));
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    point[i] = {x, y};
    exist[x][y] = true;
  }
  int ans = 0;
  sort(point.begin(), point.end(),greater<pair<int,int>>());
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      int x1 = point[i].first;
      int y1 = point[i].second;
      int x2 = point[j].first;
      int y2 = point[j].second;
      int area = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
      if (area <= ans) continue;
      int x3 = x2 - y2 + y1;
      int y3 = y2 + x2 - x1;
      int x4 = x1 - y2 + y1;
      int y4 = y1 + x2 - x1;
      if (in2(x3, y3, x4, y4)) {
        if (exist[x3][y3] && exist[x4][y4]) {
          chmax(ans, area);
        }
      }
    }
  }
  cout << ans << endl;
}