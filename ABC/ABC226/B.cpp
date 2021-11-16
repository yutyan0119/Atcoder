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
  int N;
  cin >> N;
  int L[N];
  int M = 200000 / N + 1;
  vector<vector<int>> a(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    cin >> L[i];
    for (int j = 0; j < L[i]; j++) {
      cin >> a[i][j];
    }
  }
  int count = N;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (L[i] == L[j]) {
        int check = 0;
        for (int k = 0; k < L[i]; k++) {
          if (a[i][k] == a[j][k]) {
            check++;
          }
        }
        if (check == L[i]) {
          count--;
          a[j] = a[i];
          break;
        }
      }
    }
  }
  cout << count << endl;
}