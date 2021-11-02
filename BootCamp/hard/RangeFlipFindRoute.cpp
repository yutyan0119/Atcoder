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
  int H, W;
  cin >> H >> W;
  char s[H][W];
  int count = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> s[i][j];
    }
  }
  if (s[0][0] == '#') {
    s[0][0] = '.';
    count++;
  }
  if (s[H - 1][W - 1] == '#') {
    s[H - 1][W - 1] = '.';
    count++;
  }
  int cury = 0;
  int curx = 0;
  while (curx != W - 1 || cury != H - 1) {
    if (curx + 1 <= W - 1 && s[cury][curx + 1] == '.') {
      curx++;
    } else if (cury + 1 <= H - 1 && s[cury + 1][curx] == '.') {
      cury++;
    } else if (curx + 1 <= W - 1) {
      s[cury][curx + 1] = '.';
      curx++;
      count++;
    } else if (cury + 1 <= H - 1) {
      s[cury + 1][curx] = '.';
      cury++;
      count++;
    }
  }
  cout << count << endl;
  // WA,dpを使ってやり直そう
}