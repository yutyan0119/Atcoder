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
const long long INF = 1LL << 60;
typedef long long ll;

/* ---------------------------------------------------*/

vector<bool> seen;
vector<int> order;

void rec(const vector<vector<int>>& G, int v) {
  seen[v] = true;
  for (auto next_v : G[v]) {
    if (seen[next_v]) continue;
    rec(G, next_v);
  }
  order.push_back(v);
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
  }
  seen.assign(N, false);
  order.clear();
  for (int i = 0; i < N; i++) {
    if (seen[i]) continue;
    rec(G, i);
  }
  reverse(order.begin(), order.end());
  vector<int> dp(N, 0);
  for (auto from : order) {
    for (auto to : G[from]) {
      chmax(dp[to], dp[from] + 1);
    }
  }
  cout << *max_element(dp.begin(),dp.end()) << endl;
}