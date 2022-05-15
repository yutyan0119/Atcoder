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

struct UnionFind {
  vector<int> par, siz;
  UnionFind(int n) {
    par.assign(n, -1);
    siz.assign(n, 1);
  }
  int root(int x) {
    if (par[x] == -1)
      return x;
    else
      return par[x] = root(par[x]);
  }

  bool issame(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) {
      swap(x, y);
    }
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  int size(int x) { return siz[x]; }
};

/* ---------------------------------------------------*/

double distance(double x, double y, double z, double x2, double y2, double z2) {
  return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2) + (z - z2) * (z - z2));
}

int main() {
  double T, L, X, Y, Q;
  scanf("%lf%lf%lf%lf%lf", &T, &L, &X, &Y, &Q);
  L /= 2;
  for (ll i = 0; i < Q; i++) {
    ll E;
    scanf("%lld", &E);
    E %= (ll)T;
    double nowy, nowz;
    nowy = -L * sin((double)E / T * 2 * M_PI);
    nowz = L - L * cos((double)E / T * 2 * M_PI);
    double a = distance(0, nowy, nowz, X, Y, 0);
    double b = distance(0, nowy, 0, X, Y, 0);
    double c = nowz;
    double cos = (a * a + b * b - c * c) / (2 * a * b);
    printf("%.8f\n", acos(cos) * 180 / M_PI);
  }
}