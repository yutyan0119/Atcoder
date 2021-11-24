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
  int N;cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(2*N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    C[2*i]=A[i];
    C[2*i+1]=B[i];
  }
  ll start, goal;
  ll ans = 1LL<< 60;
  for (int i = 0; i < 2*N; i++) {
    for (int j = 0; j < 2*N; j++) {
      ll sum = 0;
      start = A[i];
      goal = B[j];
      for (int k = 0; k < N; k++) {
        sum += abs(start - A[k]) + abs(A[k] - B[k]) + abs(goal - B[k]);
      }
      chmin(ans,sum);
    }
  }
  cout << ans << endl;
}