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
  int count = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  bool color[9] = {false};
  for (int i = 0; i < N; i++) {
    if (a[i] <= 399) {
      color[0] = true;
    } else if (a[i] <= 799) {
      color[1] = true;
    } else if (a[i] <= 1199) {
      color[2] = true;
    } else if (a[i] <= 1599) {
      color[3] = true;
    } else if (a[i] <= 1999) {
      color[4] = true;
    } else if (a[i] <= 2399) {
      color[5] = true;
    } else if (a[i] <= 2799) {
      color[6] = true;
    } else if (a[i] <= 3199) {
      color[7] = true;
    } else {
      color[8] = true;
      count++;
    }
  }
  int sum = 0;
  for (int i = 0; i < 8; i++) {
    sum += color[i];
  }
  cout << max(sum, 1) << " " << sum +  count << endl;
}