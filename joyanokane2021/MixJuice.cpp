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
  int N, K;
  cin >> N >> K;
  vector<int> price(N);
  for (int i = 0; i < N; i++) {
    cin >> price[i];
  }
  sort(price.begin(), price.end());
  int sum = 0;
  for (int i = 0; i < K; i++) {
    sum += price[i];
  }
  cout << sum << endl;
}