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
  int A[M], B[M];
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
  }
  vector<int> P;
  for (int i = 0; i < N; i++) {
    auto itra = find(P.begin(), P.end(), A[i]);
    auto itrb = find(P.begin(), P.end(), B[i]);
    if (itra != P.end() && itrb != P.end()) {
      if (itra > itrb) {
        cout << "-1" << endl;
        return 0;
      }
    }
  }
}