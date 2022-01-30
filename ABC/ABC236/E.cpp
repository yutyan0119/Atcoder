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
  cin >> N >> M;
  vector<ll> H(N);
  for (ll i = 0; i < N; i++) {
    cin >> H[i];
  }
  vector<vector<ll>> Root(N, vector<ll>(N, 1e9));
  for (ll i = 0; i < M; i++) {
    ll U;
    ll V;
    cin >> U >> V;
    U--;
    V--;
    if (H[U] > H[V]) {
      Root[U][V] = H[U] - H[V];
      Root[V][U] = -2 * (H[U] - H[V]);
    } else {
      Root[U][V] = -2 * (H[V] - H[U]);
      Root[V][U] = H[V] - H[U];
    }
  }
}