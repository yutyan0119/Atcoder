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
  ll minR = 1e10;
  ll maxL = 0;
  vector<ll> L(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
  }
  for (int i = 0; i < N; i++) {
    minR = min(minR, R[i]);
    maxL = max(maxL, L[i]);
    if (minR >= maxL) {
      cout << 0 << endl;
    } else if (minR < maxL) {
      cout << (maxL - minR+1) / 2 << endl;
    }
  }
}