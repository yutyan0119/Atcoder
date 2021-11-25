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
  int R, C;
  cin >> R >> C;
  vector<vector<int>> A(R, vector<int>(C));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> A[i][j];
    }
  }
  ll ans = 0;
  for (int i = 0; i < (1 << R); i++) {
    vector<vector<int>> B(R, vector<int>(C));
    for (int j = 0; j < R; j++) {
      for (int k = 0; k < C; k++) {
        B[j][k] = A[j][k];
      }
    }

    ll sum = 0;
    for (int j = 0; j < R; j++) {
      if (i & 1 << j) {
        for (int k = 0; k < C; k++) {
          B[j][k] = (A[j][k] == 0 ? 1 : 0);
        }
      }
    }
    for (int j = 0; j < C; j++) {
      int omote = 0;
      int ura = 0;
      for (int k = 0; k < R; k++) {
        if (B[k][j] == 0) {
          omote++;
        } else {
          ura++;
        }
      }
      sum += max(omote, ura);
    }
    chmax(ans, sum);
  }
  cout << ans << endl;
}