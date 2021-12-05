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
  int H;
  int W;
  cin >> H >> W;
  char c[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> c[i][j];
    }
  }
  char color[6] = "12345";
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      set<char> a;
      if (c[i][j] == '.') {
        int minx = max(j - 1, 0);
        int maxx = min(j + 1, W - 1);
        int miny = max(i - 1, 0);
        int maxy = min(i + 1, H - 1);
        a.insert(c[miny][j]);
        a.insert(c[i][minx]);
        a.insert(c[i][maxx]);
        a.insert(c[maxy][j]);
        for (int k = 0; k < 5; k++) {
          if (a.find(color[k]) == a.end()) {
            c[i][j] = color[k];
            break;
          };
        }
      }
    }
  }
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cout << c[i][j] ;
    }
    cout << endl;
  }
  return 0;
}