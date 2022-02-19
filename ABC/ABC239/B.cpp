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
  ll X;
  cin >> X;
  if(X>0){
    cout << X/10 << endl;
  }
  else if (X<0){
    if (X%10==0) cout << X/10 << endl;
    else cout << X/10-1 << endl;
  }
  else{
    cout << 0 << endl;
  }
}