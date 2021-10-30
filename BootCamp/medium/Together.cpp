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
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int count = 0;
  for (int i = 1; i <= 100000; i++) {
    int tmp = 0;
    for (int j = 0; j < N; j++) {
      if (a[j] == i || a[j] == i - 1 || a[j] == i + 1) {
        tmp++;
      }
    }
    chmax(count, tmp);
  }
  cout << count << endl;
}