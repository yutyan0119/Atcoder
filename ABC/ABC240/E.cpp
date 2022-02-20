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

vector<vector<ll>> Edge;
vector<bool> seen;
vector<ll> maxchil; //子の最大値
vector<ll> minchil; //子の最小値
vector<ll> cannum; //兄妹を考慮した可能な最少値（親から知らされる）

void dfs(ll par) {
  seen[par] = true;
  for (auto chil : Edge.at(par)) {
    if (seen.at(chil)) continue;
    cannum[chil] = cannum[par];
    dfs(chil);
    chmin(minchil.at(par), minchil.at(chil));
    chmax(maxchil[par], maxchil[chil]);
    cannum[par] = maxchil[chil] + 1;
  }
  maxchil[par] = max(maxchil[par],cannum[par]);
  minchil[par] = max(minchil[par],cannum[par]);
}

int main() {
  ll N;
  cin >> N;
  Edge.assign(N, vector<ll>());
  seen.assign(N, false);
  maxchil.assign(N, 1);
  minchil.assign(N, 1);
  cannum.assign(N, 1);
  for (ll i = 0; i < N - 1; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    Edge[a].push_back(b);
    Edge[b].push_back(a);
  }
  dfs(0);
  for (ll i = 0 ; i < N ; i ++){
    cout << minchil[i] << " " << maxchil[i] << endl;
  }
}