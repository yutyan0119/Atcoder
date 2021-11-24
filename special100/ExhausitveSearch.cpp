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
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int q;
  cin >> q;
  int m[q];
  for (int i = 0; i < q; i++) {
    cin >> m[i];
  }
  for (int k = 0; k < q; k++) {
    bool can = false;
    for (int i = 1; i < (1 << n); i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (i & 1 << j) {
          sum += A[j];
        }
      }
      if (sum == m[k]) {
        cout << "yes" << endl;
        can = true;
        break;
      }
    }
    if (!can) {
      cout << "no" << endl;
    }
  }
}