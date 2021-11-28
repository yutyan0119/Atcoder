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
  string S;
  cin >> S;
  ll ans = 0;
  ll k = 0;
  for (ll i = 0; i < N-1; i++) {
    char x = S.at(i);
    for (ll j = i + 1; j < N; j++) {
      char y = S.at(j);
      k = j;
      if (x != y) {
        k--;
        break;
      }
    }
    ans += (k + 1 - i) * (k - i) / 2;
    i = k;
  }
  cout << ans << endl;
}