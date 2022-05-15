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

int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  int M;
  cin >> M;
  vector<vector<int>> Edge(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    Edge[x - 1].push_back(y - 1);
    Edge[y - 1].push_back(x - 1);
  }
  vector<int> junban(N);
  for (int i = 0; i < N; i++) {
    junban[i] = i;
  }
  ll ans = 1e10;
  do {
    ll time = 0;
    for (int i = 0; i < N; i++) {
      int runner = junban[i];
      if (i != N - 1 && find(Edge[runner].begin(), Edge[runner].end(),
                             junban[i + 1]) != Edge[runner].end()) {
        break;
      } else {
        time += A[runner][i];
        if (i == N - 1) {
          chmin(ans, time);
        }
      }
    }
  } while (next_permutation(junban.begin(), junban.end()));
  if (ans == 1e10) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}