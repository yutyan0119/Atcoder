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
  int keta = to_string(N).length();
  ll banme = N - (ll)pow(10, keta - 1) + 1;
  ll sum = 0;
  ll mod = 998244353;

  for (int i = 1; i < keta; i++) {
    ll benri = (ll)pow(10, i - 1) % mod;
    sum += (1 + ((9 * benri)%mod)) * ((9 * benri)%mod) / 2 % mod;
    sum = sum % mod;
  }
  sum += (1 + (banme % mod)) * (banme % mod) / 2;
  cout << sum % mod << endl;
}