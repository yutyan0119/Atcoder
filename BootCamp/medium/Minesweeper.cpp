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
  string S[H];
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }
  vector<vector<int>> count(H, vector<int>(W, 0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i].at(j) == '.') {
        for (int k = max(i - 1, 0); k <= min(i + 1, H - 1); k++) {
          for (int l = max(j - 1, 0); l <= min(j + 1, W - 1); l++) {
            if (S[k].at(l) == '#') count[i][j]++;
          }
        }
      } else {
        count[i][j] = -1;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (count[i][j] == -1) {
        cout << "#";
      } else {
        cout << count[i][j];
      }
    }
    cout << endl;
  }
}