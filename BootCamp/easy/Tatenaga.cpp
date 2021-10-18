#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for(int i = s; i <e ; i++)

/* ---------------------------------------------------*/

int main() {
  int H, W;
  cin >> H >> W;
  char C[H][W];
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> C[i][j];
    }
  }
  char D[2*H][W];
  for (int i = 0; i < 2*H; i+=2)
  {
    for (int j = 0; j < W; j++)
    {
      D[i][j] = C[i/2][j];
      D[i+1][j] = C[i/2][j];
    }
  }
  for (int i = 0; i < 2*H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cout << D[i][j] ;
    }
    cout << endl;
  }
 return 0; 
}