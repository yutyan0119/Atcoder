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
  int N,X;
  cin >> N>>X;
  int A[N+1];
  for (int i = 1; i < N+1; i++)
  {
    cin >> A[i];
  }
  vector <int> B(N+1,0);
  B[X] = 1;
  while (true)
  { 
    if (B[A[X]]==0){
      B[A[X]] = 1;
      X=A[X];
    }else if (B[A[X]]==1){
      break;
    }
  }
  int sum = 0;
  for (int i = 1; i < N+1; i++)
  {
    sum+=B[i];
  }
  cout << sum << endl;
}