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

/* ---------------------------------------------------*/

int main() {
  int H, W;
  cin >> H >> W;
  char a[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < H + 2; i++) {
    for (int j = 0; j < W + 2; j++) {
      if (i==0 || i == H+1 || j==0 || j== W+1){
        cout << "#" ;
      }
      else {
        cout << a[i-1][j-1] ;
      }
    }
    cout << endl;
  }
}