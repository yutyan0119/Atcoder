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

int main() {
  int V, E, s;
  cin >> V >> E >> s;
  vector<vector<Edge>> Graph(V);
  vector<ll> cost(V, 1e9);
  for (int i = 0; i < E; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    Graph[from].push_back(Edge(to, weight));
  }
  cost[s] = 0;
  vector<bool> seen(V, false);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      que;
  que.push(make_pair(cost[s], s));
  while (!que.empty()) {
    int v = que.top().second;
    que.pop();

    if (seen[v]) continue;

    for (auto e : Graph[v]) {
      if (chmin(cost[e.to], cost[v] + e.weight))
        que.push(make_pair(cost[e.to], e.to));
    }
    seen[v] = true;
  }

  for (int v = 0; v < V; ++v) {
    if (cost[v] == 1e9)
      cout << "INF" << endl;
    else
      cout << cost[v] << endl;
  }
}