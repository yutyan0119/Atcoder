#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

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
ll N, M;
vector<vector<ll>> G;
ll S, T;

ll solve() {
  vector<vector<ll>> score(N, vector<ll>(3, -1));
  score[S][0] = 0;
  queue<pair<int, int>> que;
  que.push({S, 0});
  while (!que.empty()) {
    pair<int, int> cur = que.front();
    que.pop();
    int v = cur.first;
    int mod = cur.second;
    for (auto next_v : G[v]) {
      int nextmod = (mod + 1) % 3;
      if (score[next_v][nextmod] == -1) {
        score[next_v][nextmod] = score[v][mod] + 1;
        que.push({next_v, nextmod});
      }
    }
  }
  if (score[T][0] == -1) {
    return -1;
  } else {
    return score[T][0] / 3;
  }
}

int main() {
  cin >> N >> M;
  G.assign(N, vector<ll>());
  for (int i = 0; i < M; i++) {
    ll from, to;
    cin >> from >> to;
    from--;
    to--;
    G.at(from).push_back(to);
  }
  cin >> S >> T;
  --S;
  --T;
  cout << solve() << endl;
}