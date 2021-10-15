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
  string W[N];
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }
  bool rule = true;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      if (W[i] == W[j]) {
        rule = false;
        break;
      }
    }
  }
  for (int i = 0; i < N - 1; i++) {
    if (W[i].at((int)W[i].size() - 1) != W[i + 1].at(0)){
      rule = false;
      break;
    }
  }
  cout << (rule ? "Yes" : "No") << endl;
}