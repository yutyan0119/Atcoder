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
    minR = min(minR, R[i]);
    maxL = max(maxL, L[i]);
  }
  ll ansR = 0;
  ll ansL = 0;
  for (int i = 0; i < N; i++) {
    if (minR < L[i]) {
      ansR += L[i] - minR;
    } else if (minR > R[i]) {
      ansR += minR - R[i];
    }
    if (maxL < L[i]) {
      ansL += L[i] - maxL;
    } else if (maxL > R[i]) {
      ansL += maxL - R[i];
    }
    cout << min(ansL, ansR) << endl;
  }
}