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
  ll count = 0;
  if (N % 2 == 0) {
    N /= 10;
    count += N;
    while (N > 0) {
      N /= 5;
      count += N;
    }
  }
  cout << count << endl;
}