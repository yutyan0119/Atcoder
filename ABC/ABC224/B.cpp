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

#define rep(i1, s, e) for (int i1 = s; i1 < e; i1++)

/* ---------------------------------------------------*/

int main() {
  int H, W;
  cin >> H >> W;
  int A[H][W];
  for (int i1 = 0; i1 < H; i1++) {
    for (int i2 = 0; i2 < W; i2++) {
      cin >> A[i1][i2];
    }
  }
  bool can = true;
  for (int i1 = 0; i1 < H; i1++) {
    for (int i2 = i1; i2 < H; i2++) {
      for (int j1 = 0; j1 < W; j1++) {
        for (int j2 = j1; j2 < W; j2++) {
          if (A[i1][j1] + A[i2][j2] > A[i2][j1] + A[i1][j2]) can = false;
        }
      }
    }
  }
  cout << ((can)?"Yes":"No") << endl;
}