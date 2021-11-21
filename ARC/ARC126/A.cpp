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
  int T;
  cin >> T;
  ll res[T];
  for (int i = 0; i < T; i++) {
    ll ans = 0;
    ll N2, N3, N4;
    cin >> N2 >> N3 >> N4;
    ll m = min(N3 / 2, N4);
    ans += m;
    N3 -= (2 * m);
    N4 -= m;
    m = min(N2, N4 / 2);
    ans += m;
    N2 -= m;
    N4 -= (2 * m);
    m = min(N3 / 2, N2 / 2);
    ans += m;
    N2 -= (m * 2);
    N3 -= (m * 2);
    m = min(N2 / 3, N4);
    ans += m;
    N2 -= m * 3;
    N4 -= m;
    m = N2 / 5;
    ans += m;
    res[i] = ans;
  }
  for (int i = 0; i < T; i++) {
    cout << res[i] << endl;
  }

  return 0;
}