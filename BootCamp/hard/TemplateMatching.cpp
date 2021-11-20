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
  int N, M;
  cin >> N >> M;
  char A[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
    {
      cin >> A[i][j];
    }
  }
  char B[M][M];
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++)
    {
      cin >> B[i][j];
    }
    
  }
  bool can;
  for (int i = 0; i < N-M+1; i++) {
    for (int j = 0; j < N - M + 1; j++) {
      can = true;
      for (int k = 0; k < M; k++) {
        if (!can) {
          break;
        }
        for (int l = 0; l < M; l++) {
          if (A[i+k][j+l] != B[k][l]) {
            can = false;
            break;
          }
        }
      }
      if (can) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  if (!can) {
    cout << "No" << endl;
  }
}