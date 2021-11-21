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
  ll N, ans=0;
  cin >> N;
  for (ll i = 1; i <= N; i = i * 10 + 1) {
    for (ll j = 1; i * j <= N; j *= 10) { //i*jが1...10..0に相当
      ans+= min(j,N-i*j+1); 
    }
  }
  cout << ans << endl;
}
/*
11000の時を考えれば
普通なら1000=j個あるが、
場合によってこうなるのがわかる
*/