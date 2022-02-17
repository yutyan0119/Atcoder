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

ll patty[51], tot[51];

ll solve(int N, ll X) {
  if (N == 0) return 1;
  if (X < 1) return 0;
  X--;
  if (X < tot[N - 1]) return solve(N - 1, X);
  X -= tot[N - 1];
  if (X < 1) return patty[N - 1] + 1;
  X--;
  if (X < tot[N - 1]) return patty[N - 1] + 1 + solve(N - 1, X);
  X -= tot[N - 1];
  return patty[N - 1] * 2 + 1;
}

int main() {
  int N;
  cin >> N;
  ll X;
  cin >> X;
  X--;
  tot[0] = 1;
  patty[0] = 1;
  for (ll i = 1; i <= N; i++) {
    tot[i] = tot[i - 1] * 2 + 3;
    patty[i] = patty[i - 1] * 2 + 1;
  }
  cout << solve(N,X) << endl;
}