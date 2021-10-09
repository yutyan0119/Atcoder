#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for(int i = s; i <e ; i++)

/* ---------------------------------------------------*/

int main() {
  int N;
  int A[N],B[N],C[N],D[N];
  for (int i = 1; i < N; i++)
  { A[0] = 0;
    B[0] = 0;
    C[0] = 0;
    cin >> A[i] >> B[i] >> C[i];
  }
  
}