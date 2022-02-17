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
  ll n10 = 1;
  ll n8 = 1;
  ll n9 = 1;
  ll mod = 1e9 + 7;
  for (ll i = 0; i < N; i++) {
    n10 *= 10;
    n8 *= 8;
    n9 *= 9;
    n10 = n10 % mod;
    n9 = n9 % mod;
    n8 = n8 % mod;
  }
  ll ans = (n10 + n8 - 2 * n9) % mod;
  while (true) {
    if (0 <= ans && ans < mod) {
      break;
    } else {
      ans += mod;
    }
  }

  cout << ans << endl;
}