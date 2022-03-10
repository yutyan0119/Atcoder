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

const ll N = (ll)pow(2, 20);

int main() {
  ll Q;
  scanf("%lld", &Q);
  vector<ll> M(N);
  vector<bool> B(N, false);
  for (ll i = 0; i < Q; i++) {
    ll t, x;
    scanf("%lld%lld", &t, &x);
    if (t == 1) {
      ll h = x;
      while (true) {
        ll hmodn = h % N;
        if (!B[hmodn]) {
          M[hmodn] = x;
          B[hmodn] = true;
          break;
        }
        ++h;
      }
    } else {
      ll hmodn = x % N;
      if (!B[hmodn]) {
        printf("-1\n");
      } else {
        printf("%lld\n", M[hmodn]);
      }
    }
  }
}