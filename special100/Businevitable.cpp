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

#define INF 1e15

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> dp(N, vector<ll>(N, INF));
  for (int i = 0; i < M; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    a--;
    b--;
    dp[a][b] = t;
    dp[b][a] = t;
  }
  for (int i = 0; i < N; i++) {
    dp[i][i] = 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        chmin(dp[j][k], dp[j][i] + dp[i][k]);
      }
    }
  }
  ll min = INF;
  ll place;
  for (int i = 0; i < N; i++) {
    if (chmin(min, *max_element(dp[i].begin(), dp[i].end()))) {
      place = i;
    }
  }
  cout << min << endl;
}