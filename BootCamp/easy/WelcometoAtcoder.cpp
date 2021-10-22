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
  int p[M];
  string s[M];
  for (int i = 0; i < M; i++) {
    cin >> p[i] >> s[i];
  }

  int solve[M] = {-1};
  int penalty = 0;
  for (int i = 0; i < M; i++) {
    if (s[i] == "AC") {
      solve[p[i] - 1] = 1;
    }else{}
  }
  int ac = 0;
  for (int i = 0; i < M; i++) {
    if (solve[i]) {
      ac++;
    } else {
      penalty++;
    }
  }
  cout << ac << " " << penalty << endl;
}