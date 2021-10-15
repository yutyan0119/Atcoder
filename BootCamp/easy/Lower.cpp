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
  int N;
  cin >> N;
  int H[N];
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  int count = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i != N-1 && H[i] >= H[i + 1] ) {
      count++;
    } else {
      chmax(ans,count);
      count = 0;
    }
  }
  cout << ans << endl;
}