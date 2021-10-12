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
  cin >> N;
  int P[N];
  rep(i,0,N) cin >> P[i];
  int M[N+1];
  M[0]=N+10;
  int ans = 0;
  for (int i = 1; i < N; i++)
  {
    M[i] = M[i-1]>P[i-1] ? P[i-1] : M[i-1];
  }
  for (int i = 0; i < N; i++)
  {
    if  (P[i]<=M[i]) ans++;
  }
  cout << ans << endl;
}