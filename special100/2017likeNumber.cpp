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
vector<bool> isprime(100020, true);

void prime() {
  isprime[1] = isprime[0] = false;
  for (ll i = 0; i < 100020; i++) {
    if (isprime[i] == false) continue;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        isprime[i] = false;
        for (int k = 0; k * i < 100020; k++) {
          isprime[i * k] = false;
        }
        break;
      }
    }
  }
}

bool is2017like(int i) {
  if (i % 2 == 0) {
    return false;
  }
  if (isprime[i] && isprime[(i + 1) / 2])
    return true;
  else
    return false;
}

int main() {
  prime();
  vector<int> howmany_2017like(100020, 0);
  for (int i = 2; i < 100020; i++) {
    howmany_2017like[i] = howmany_2017like[i - 1] + is2017like(i - 1);
  }

  int Q;
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    int l, r;
    scanf("%d", &l);
    scanf("%d", &r);
    printf("%d\n", howmany_2017like[r + 1] - howmany_2017like[l]);
  }
  return 0;
}