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
  ll mod = 1000000007;
  ll N;
  ll K;
  cin >> N >> K;
  int a[N];
  int c[N] = {0};
  int d[N] = {0};
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    int base = a[i];
    for (int j = i + 1; j < N; j++) {
      int compare = a[j];
      if (base > compare) {
        c[i]++;
      }
    }
    for (int j = 0; j < N; j++) {
      int compare = a[j];
      if (base > compare) {
        d[i]++;
      }
    }
  }
  ll csum = 0;
  ll dsum = 0;
  for (int i = 0; i < N; i++) {
    csum += c[i];
    dsum += d[i];
    csum %= mod;
    dsum %= mod;
  }
  K %= mod;
  ll ans = (K * csum + (K * (K - 1)/2)%mod * dsum) % mod;
  cout << ans << endl;
}