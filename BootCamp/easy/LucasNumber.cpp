#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

/* ---------------------------------------------------*/

int main() {
  int N;
  cin >> N;
  ll L[87];
  L[0] = 2;
  L[1] = 1;
  for (int i = 2; i < N+1; i++)
  {
    L[i] = L[i-2] + L[i-1];
  }
  cout << L[N] << endl;
}
