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

/* ---------------------------------------------------*/

int main() {
  int n, l;
  cin >> n >> l;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n);
  for (int i = 0; i < n; i++) {
    cout << s[i];
  }
  cout << endl;
}