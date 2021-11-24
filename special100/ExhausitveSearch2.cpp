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

int n;
vector<int> A;
bool solve(int i, int m);

int main() {
  cin >> n;
  A.resize(n);
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
    if (solve(0, m[k])) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}

bool solve(int i, int m) {  //和mが残りの整数の和で表せるか
  if (m == 0) {
    return true;
  }
  if (i >= n) {
    return false;
  }
  return (solve(i + 1, m - A[i]) || solve(i + 1, m));
}