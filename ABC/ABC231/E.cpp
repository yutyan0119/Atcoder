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
  for (int i = 1; i < N; i++) {
    Y = preY;
    cout << A[i] << " " << Y << " " << A[i - 1] << endl;
    otsuricount += (A[i] - Y % A[i]) / A[i - 1];
    Y += A[i] - Y % A[i];
    preY = Y;
    ll count = 0;
    for (int j = N - 1; j >= i; j--) {
      count += Y / A[j];
      Y -= A[i] * (Y / A[j]);
      if (Y == 0) {
        break;
      }
    }
    chmin(mincount, otsuricount + count);
    cerr << "count = " << count << "otsuri = " << otsuricount << endl;
  }
  cout << mincount << endl;
}