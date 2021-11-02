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
  string S;
  cin >> S;
  int N = (int)S.size();
  int a[N];
  int lastR = 0;
  int lastL = N - 1;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'R') {
      lastR = i;
    } else {
      a[i] = i - lastR - 1;
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    if (S.at(i) == 'L') {
      lastL = i;
    } else {
      a[i] = i - lastL + 1;
    }
  }
  int count[N] = {0};
  for (int i = 0; i < N; i++)
  {
    count[i-(a[i]+a[i]%2)]++;
  }
  for (int i = 0; i < N; i++)
  {
    cout << count[i] << " ";
  }
  cout << endl;
}