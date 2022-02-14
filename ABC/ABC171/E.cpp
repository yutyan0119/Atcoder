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
  vector<ll> a(N);
  ll XOR = 0;
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
    if (i != 0) XOR = XOR ^ a[i];
  }
  ll dif = XOR ^ a[0];
  for (ll i = 0; i < N; i++) {
    cout << (a[i] ^ dif) << endl;
  }
}