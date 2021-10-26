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
  int L = (int)S.size();
  if (L % 2 == 1) S = S.substr(0, L - 1);
  int N = (int)S.size();
  string fS = S.substr(0, S.size() / 2);
  string bS = S.substr(S.size() / 2, S.size() / 2);
  int K = N;
  int M = K / 2;
  for (int i = 0; i < N; i++) {
    if (fS == bS && 2 * M != L) {
      cout << 2 * M << endl;
      return 0;
    } else {
      K -= 2;
      M = K / 2;
      fS = S.substr(0, M);
      bS = S.substr(M, M);
    }
  }
}