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
  ll N, K;
  scanf("%lld%lld", &N, &K);
  ll res = 0;
  if (K == 0) {
    printf("%lld\n", N * N);
    return 0;
  }
  for (ll i = K + 1; i <= N; i++) {
    ll num = (N - K) / i;
    res += (i - K) * num;
    if (N < i * (num + 1)) {
      res += N - (K + num * i) + 1;
    } else {
      res += i * (num + 1) - (K + num * i);
    }
  }
  printf("%lld\n", res);
}