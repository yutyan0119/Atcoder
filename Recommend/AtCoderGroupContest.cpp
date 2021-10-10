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
  long long a[3*N];
  long long ans = 0;
  rep(i,0,3*N){cin >> a[i];}
  sort(a,a+3*N, greater<long long>());
  for (int i = 1, j=0 ;  j < N; i+=2, j++)
  {
    ans += a[i];
  }
  cout << ans << endl;
}