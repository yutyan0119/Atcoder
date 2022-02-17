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

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1);
  A[0] = 0;
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    A[i] = (A[i - 1] + a) % 360;
  }
  sort(A.begin(), A.end());
  int ans = 0;
  for (int i = 0; i < N; i++) {
    chmax(ans, A[i + 1] - A[i]);
  }
  chmax(ans, -A[N] + 360);
  cout << ans << endl;
}