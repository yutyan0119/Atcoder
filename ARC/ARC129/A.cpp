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


ll powll2(ll n){
  ll res = 1;
  for (ll i = 0; i < n; i++)
  {
    res*=2;
  }//2の累乗を計算して返すプログラム
  return res;
}
int main() {
  ll N, L, R;
  cin >> N >> L >> R;
  ll ketaL, ketaR;
  for (ll i = 61; i >= 0; --i) {
    if (L & (ll)1 << i) {
      ketaL = i + 1;
      break;
    }
  }
  for (ll i = 61; i >= 0; --i) {
    if (R & (ll)1 << i) {
      ketaR = i + 1;
      break;
    }
  }
  ll sum = 0;
  for (ll i = 61; i >= 0; --i) {
    if (N & (ll)1 << i) {  // i+1桁目が立ってる
      if(i+1>ketaL && i+1<ketaR){
        sum += (ll)powll2(i);
      }else if (i+1==ketaL && i+1<ketaR){
        sum += (ll)2*powll2(i)-L;
      }else if (i+1>ketaL && i+1 == ketaR){
        sum += (ll)R-powll2(i)+1;
      }else if (i+1 == ketaL && i+1 == ketaR){
        sum += R-L+1;
      }
    }
  }
  cout << sum << endl;
}