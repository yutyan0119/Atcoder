#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for (int i = s; i < e; i++)

typedef long long ll;

/* ---------------------------------------------------*/

ll fibonacci(int n, vector<int> &memo) {
  if (memo[n] != -1) return memo[n];
  memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
  return memo[n];
}

int main() {
  int n;
  cin >> n;
  vector<int> memo(n + 1, -1);
  memo[0] = 1;
  memo[1] = 1;
  cout << fibonacci(n, memo) << endl;
}