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
  char A[N][N]
  for (int i = 0; i < N; i++) {
    cin >> A[];
  }
  vector<string> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  bool can;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N - M + 1; j++) {
      can = true;
      for (int k = 0; k < M; k++) {
        if (!can) {
          break;
        }
        for (int l = 0; l < M; l++) {
          if (A.at(i + k).at(j + l) != B.at(k).at(l)) {
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