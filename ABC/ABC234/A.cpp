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
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  if (X <= A) {
    printf("%d\n", 1);
  } else if (A < X && X <= B) {
    printf("%.10f\n", (float)C / (float)(B - A));
  } else {
    printf("0\n");
  }
}