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

void tate(string S[], string U[], int N,
          int k) {  // N行N列のSをkだけ上に動かす操作
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (0 <= i - k && i - k <= N - 1) {
        U[i][j] = S[i - k][j];
      } else {
        U[i][j] = '.';
      }
    }
  }
}

void yoko(string S[], string U[], int N,
          int k) {  // N行N列のSをkだけ横に動かす操作
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (0 <= j - k && j - k <= N - 1) {
        U[i][j] = S[j - k][j];
      } else {
        U[i][j] = '.';
      }
    }
  }
}

void rotate(string U[], int N, int p) {  // N行N列の文字列Uをp回左回りに回転する
  string T[N];
  for (int i = 0; i < N; i++) {
    T[i] = U[i];
  }
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        U[k][j] = T[j][k];
      }
    }
    for (int j = 0; j < N; j++) {
      T[i] = U[i];
    }
  }
}

int main() {
  int N;
  cin >> N;
  string S[N];
  string T[N];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }
  string U[N];
  for (int i = 0; i < N; i++) {
    U[i] = S[i];
  }
  for (int i = -N; i <= N; i++) {
    for (int j = -N; j <= N; j++) {
      tate(S, U, N, i);
      yoko(S, U, N, j);
      for (int k = 1; k <= 3; k++) {
        rotate(U, N, k);
        int count = 0;
        for (int l = 0; l < N; l++) {
          if (U[l] == T[l]) {
            count++;
          }
          if (count == N){
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
