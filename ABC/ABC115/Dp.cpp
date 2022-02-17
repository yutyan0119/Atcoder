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

set<pair<ll,ll> S;

ll solve(int N, ll X) {
  if (M[N][X] != 0) {
    return M[N][X];
  } else if (X <= N) {
    M[N][X] = 0;
    return 0;
  } else if (X <= ((ll)pow(2, N + 2) - 3) / 2) {
    M[N][X] = solve(N-1,X-1);
    return M[N][X];
  } else {
    M[N][X] = 1 + solve(N - 1, (ll)pow(2, N + 1) - 3) +
           solve(N - 1, X - 2 - ((ll)pow(2, N + 2) - 3) / 2);
    return M[N][X];
  }
}

int main() {
  int N;
  cin >> N;
  ll X;
  cin >> X;
  M[0][0] = 0;
  M[0][1] = 1;
  cout << solve(N, X) << endl;
}