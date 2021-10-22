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
  int N, K;
  cin >> N >> K;
  int h[N];
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  sort(h,h+N);
  int min = 1000000000;
  for (int i = 0; i+K-1 < N ; i++)
  {
    chmin(min,h[i+K-1]-h[i]);
  }
  cout << min << endl;
}