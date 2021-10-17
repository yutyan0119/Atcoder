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
  double A[N];
  double B[N];
  double ans = 0;
  vector <double> L(N + 1,0);  // iマス目の左への到達時刻
  L[0] = 0;
  double T = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    L[i + 1] += (L[i] + (A[i] / B[i]));
  }
  T = L[N]/2;
  int masu = 0;
  for (int i = 0; i < N+1; i++)
  {
    if (L[i] > T){
      masu = i-1;
      break;
    }
  }
  for (int i = 0; i < masu; i++)
  {
    ans += A[i];
  }
  ans += (T-L[masu])*B[masu];
  cout << ans << endl;
}