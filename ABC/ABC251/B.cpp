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
  ll W;
  cin >> N >> W;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  set<ll> S;
  for (ll i = 0; i < N; i++) {
    if (A[i] <= W) {
      S.insert(A[i]);
    } else {
      break;
    }
    for (ll j = i + 1; j < N; j++) {
      if (A[i] + A[j] <= W) {
        S.insert(A[i] + A[j]);
      } else {
        break;
      }
      for (ll k = j + 1; k < N; k++) {
        if (A[i] + A[j] + A[k] <= W) {
          S.insert(A[i] + A[j] + A[k]);
        } else {
          break;
        }
      }
    }
  }
  cout << S.size() << "\n";
}