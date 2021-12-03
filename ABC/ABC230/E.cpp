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
  ll N;
  cin >> N;
  ll sum = 0;
  for (int i = 1; i <= N/2; i++){
    ll ac = 0;
    ll wa = N+1;
    while (wa-ac > 1){
      ll mid = (ac+wa)/2;
      if(N/mid<=i){
        ac = mid;
      }
    }
  }
  
  cout << sum  << endl;
}