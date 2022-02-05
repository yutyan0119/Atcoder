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

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      cout << A[j][i];
      if (j != H - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}