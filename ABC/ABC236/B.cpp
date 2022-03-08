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

#define rep(i1, s, e) for (int i1 = s; i1 < e; i1++)

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  ll N;
  scanf("%lld", &N);
  vector<int> num(N, 4);
  vector<bool> card(N, true);
  for (ll i = 0; i < 4 * N - 1; i++) {
    ll a;
    scanf("%lld", &a);
    a--;
    num[a]--;
    if (num[a] == 0) card[a] = false;
  }
  for (ll i = 0; i < N; i++) {
    if (card[i]) {
      printf("%lld\n", i + 1);
      break;
    }
  }
}