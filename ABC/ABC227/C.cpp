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
  ll count = 0;
  ll x = (int)pow(N,1.0/3.0)+1;
  for (ll i = 1; i <= x; i++) {
    for (ll j = i; j <= (int)sqrt(N/i+1); j++) {
      count += N/(i*j)-j+1;
    }
  }
  cout << count << endl;
}