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
  vector<pair<ll, ll>> a(N);
  vector<ll> b(N);
  for (ll i = 0; i < N; i++) {
    ll p;
    scanf("%lld", &p);
    a[i] = make_pair(p, i);
    scanf("%lld", &b[i]);
  }
  sort(a.begin(), a.end());
  ll num = 0;
  for (ll i = 0; i < N; i++) {
    num += b[a[i].second];
    if (num >= K) {
      printf("%lld\n", a[i].first);
      return 0;
    }
  }
}