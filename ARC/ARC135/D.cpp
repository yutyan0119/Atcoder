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
  vector<ll> S(N);
  vector<ll> minA(N + 2, 0);
  vector<ll> A(N + 2, 0);
  for (ll i = 0; i < N; i++) {
    ll a;
    cin >> a;
    S[i] = a;
    if (i >= 1) {
      ll sa = S[i - 1] - S[i];
      if (sa > 0) {
        minA[i - 1] = sa;
      } else {
        minA[i + 2] = -sa;
      }
    }
  }
  for (ll i = 0; i < N; i++) {
    ll sum = minA[i] + minA[i + 1] + minA[i + 2];
    if (sum > S[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  A[0] = minA[0];
  A[1] = minA[1];
  A[2] = S[0]-A[0]-A[1];
  for (ll i = 3; i < N + 2; i++) {
    A[i] = A[i - 3] + S[i - 2] - S[i - 3];
  }
  cout << "Yes" << endl;
  for (ll i = 0; i < N + 2; i++) {
    cout << A[i];
    if (i < N + 1) {
      cout << " ";
    }
  }
  cout << endl;
}