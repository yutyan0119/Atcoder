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
  int a[N];
  int b[N];
  int c[N];
  int MOD = 998244353;
  rep(i,0,N){
    cin >> a[i];
  }
  rep(i,0,N){
    cin >> b[i];
  }
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = a[i]; j < b[i+1]; j++)
    {
      
    }
    
  }
  
}