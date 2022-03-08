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
  ll N, M;
  scanf("%lld%lld", &N, &M);
  vector<bool> stop(N, false);
  map<string, ll> station;
  for (ll i = 0; i < N; i++) {
    string S;
    cin >> S;
    station[S] = i;
  }
  for (ll i = 0; i < M; i++) {
    string S;
    cin >> S;
    stop[station[S]] = true;
  }
  for (ll i = 0; i < N; i++) {
    if (stop[i]) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
