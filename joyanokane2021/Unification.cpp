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
  string S;
  cin >> S;
  int N = S.size();
  int count[2] = {0, 0};
  for (int i = 0; i < N; i++) {
    count[S.at(i) - '0']++;
  }
  cout << min(count[0], count[1]) * 2 << endl;
}