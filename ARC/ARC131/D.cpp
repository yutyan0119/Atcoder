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
  int N, M, D;
  cin >> N >> M >> D;
  vector<ll> r(M + 1);
  ll maxrange = 0;
  for (int i = 0; i < M + 1; i++) {
    cin >> r.at(i);
    chmax(maxrange, r.at(i));
  }
  vector<ll> s(M);
  for (int i = 0; i < M; i++) {
    cin >> s.at(i);
  }
  ll score = 0;
  vector<ll> arrow(N);
  if (N % 2 == 1) {
    for (int i = 0; i < N; i++) {
      arrow.at(i) = -((N - 1) / 2 - i) * (D + 1);
    }
  } else {
    for (int i = 0; i < N; i++) {
      arrow.at(i) = -(N / 2 + 1 - i) + (D + 1);
    }
  }
  for (int i = 0; i <= r.at(1); i++)
  {
    for (int j = 0; j < N; j++)
    {
      
    }
    
  }
  
}