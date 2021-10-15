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
  int N, M;
  cin >> N >> M;
  int a[M], b[M];
  int count[N] = {0};
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[j] - 1 == i) count[i]++;
      if (b[j] - 1 == i) count[i]++;
    }
  }
  for (int i = 0; i < N; i++)
  {
    cout << count[i] << endl;
  }
  
}