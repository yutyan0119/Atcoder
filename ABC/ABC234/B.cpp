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

#define rep(i1, s, e) for (int i1 = s; i1 < e; i1++)

typedef long long ll;

/* ---------------------------------------------------*/

double length(pair<int, int> p1, pair<int, int> p2) {
  int x1 = p1.first;
  int y1 = p1.second;
  int x2 = p2.first;
  int y2 = p2.second;
  ll len2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(len2);
}

int main() {
  ll N;
  cin >> N;
  vector<pair<int, int>> p(N);
  for (ll i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }
  double ans = 0;
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      chmax(ans, length(p[i], p[j]));
    }
  }
  printf("%.8f\n", ans);
}