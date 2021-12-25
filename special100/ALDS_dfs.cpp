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

vector<bool> seen;

void dfs(vector<vector<int> >& G, int v, int& time, vector<int>& d,
         vector<int>& f) {
  seen[v] = true;
  d[v] = time;
  time++;
  for (int next_v : G[v]) {
    if (seen[next_v]) continue;
    dfs(G, next_v, time, d, f);
  }
  f[v] = time;
  time++;
  return;
}

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  vector<int> f(N);
  vector<vector<int> > G(N);
  int time = 1;
  for (int i = 0; i < N; i++) {
    int n;
    int k;
    cin >> n >> k;
    --n;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--;
      G[n].push_back(v);
    }
  }
  seen.assign(N, false);
  dfs(G, 0, time, d, f);
  for (int i = 0; i < N; i++) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }
  return 0;
}