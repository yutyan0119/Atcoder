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
  int N;
  cin >> N;
  ll X;
  cin >> X;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  ll mincount = 0;
  ll Y = X;
  for (int i = N - 1; i >= 0; i--) {
    mincount += Y / A[i];
    Y -= A[i] * (Y / A[i]);
    if (Y == 0) {
      break;
    }
  }
  ll otsuricount = 0;
  Y = X;
  ll preY = X;
  for (ll i = X;;)
  {

  }
  
  cout << mincount << endl;
}