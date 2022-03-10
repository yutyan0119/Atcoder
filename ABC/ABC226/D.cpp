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

bool souji(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first;
  int y1 = p1.second;
  int x2 = p2.first;
  int y2 = p2.second;
  if (x1 == 0) {
    if (x2 != 0) return false;
    if (x2 == 0) {
      if (y2 % y1) return false;
      if (y2 / y1 <= 0) return false;
      return true;
    }
  }
  if (y1 == 0) {
    if (y2 != 0) return false;
    if (y2 == 0) {
      if (x2 % x1) return false;
      if (x2 / x1 <= 0) return false;
      return true;
    }
  }
  if (x2 % x1) return false;
  if (y2 % y1) return false;
  if (x2 / x1 != y2 / y1) return false;
  if (x2 / x1 <= 0) return false;
  return true;
}

int main() {
  int N;
  scanf("%d", &N);
  set<pair<int, int>> s;
  vector<int> x(N);
  vector<int> y(N);
  vector<pair<int, int>> P;
  vector<pair<int, int>> P2;
  for (int i = 0; i < N; i++) {
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      int g = gcd(dx, dy);
      dx /= g;
      dy /= g;
      s.insert(make_pair(dx, dy));
    }
  }
  printf("%ld\n", s.size());
}