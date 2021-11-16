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
  int S[N];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  int count = 0;
  for (int i = 0; i < N; i++) {
    bool ans = false;
    for (int a = 1; a <= 250; a++) {
      if (ans) break;
      for (int b = 1; b <= 250; b++) {
        if (4 * a * b + 3 * a + 3 * b == S[i]) {
          ans = true;
          break;
        }
      }
    }
    if(!ans)count++;
  }
  cout << count << endl;
}