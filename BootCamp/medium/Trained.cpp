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
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int button = 1;
  int count = 0;
  set<int> b;
  b.insert(1);
  for (int i = 0; i < N; i++) {
    button = a[button - 1];
    count++;
    if (b.find(button) != b.end()) {
      cout << -1 << endl;
      return 0;
    }
    if (button == 2) {
      cout << count << endl;
      return 0;
    }
  }
  cout << -1 <<endl;
}