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

struct Edge {
  int to;
  int weight;
  Edge(int to2, int weight2) {
    to = to2;
    weight = weight2;
  }
};

vector<vector<Edge>> G;

ll djikstra(int from, int to) {
  vector<bool> seen(G.size(), false);
  vector<ll> cost(G.size(), 1e10);
  cost[from] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que;
  que.push(make_pair(0, from));
  while (!que.empty()) {
    ll mincost = que.top().first;
    int minp = que.top().second;
    que.pop();
    if (seen.at(minp)) continue;
    seen.at(minp) = true;
    for (auto e : G[minp]) {
      if (chmin(cost.at(e.to), mincost + e.weight)) {
        que.push(make_pair(cost.at(e.to), e.to));
      }
    }
  }
  return cost[to];
}

int main() {
  int n, k;
  cin >> n >> k;
  G.assign(n, vector<Edge>());
  for (int i = 0; i < k; i++) {
    int query;
    cin >> query;
    if (query) {
      int c, d, e;
      cin >> c >> d >> e;
      c--;
      d--;
      G.at(c).push_back(Edge(d, e));
      G.at(d).push_back(Edge(c, e));
    } else {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      ll cost = djikstra(a, b);
      if (cost == 1e10) {
        cout << -1 << "\n";
      } else {
        cout << cost << "\n";
      }
    }
  }
}