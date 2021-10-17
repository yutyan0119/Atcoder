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
  int A[N];
  int B[N];
  double L[N + 1];  // iマス目の左への到達時刻
  L[0] = 0;
  double R[N + 1];  // iマス目の右への到達時刻
  R[0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    L[i + 1] += L[i] + A[i] / B[i];
  }
  for (int i = 0; i < N; i++) {
    R[i + 1] += R[i] + A[N - 1 - i] / B[N - 1 - i];
  }
  double ans = 0;
  for (int i = 0; i < N + 1; i++) {
    if (L[i] < R[N - i] && L[i + 1] > R[N - i - 1]) {
      if (L[i] > R[N - i - 1]) {
        double def = A[i] - B[i] * (L[i] - R[N - i - 1]);
        double time_ai = def / (2 * B[i]);
        for (int j = 0; j < i; j++) {
          ans += A[j];
        }
        ans += B[i] * time_ai;
      }
      if(R[N-i-1]>L[i]){
        double def = A[i]-B[i]*(R[N-i-1]-L[i]);
        double time_ai = def / (2*B[i]);
        for (int j = 0; j < i; j++)
        {
          ans += A[j];
        }
        ans += B[i] * (R[N-i-1]-L[i]+time_ai);
      }
    }
  }
  cout << ans << endl;
}