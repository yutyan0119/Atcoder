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
  int x,y;cin >> x >> y;
  int ans = 0;
  for (int i = 0; i < 10000; i++)
  {
    if(x+i*10 >= y){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}