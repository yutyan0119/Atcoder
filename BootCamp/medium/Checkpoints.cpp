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

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<ll, ll>> s(N);
  vector<pair<ll, ll>> c(M);
  for (int i = 0; i < N; i++) {
    cin >> s[i].first >> s[i].second;
  }
  for (int i = 0; i < M; i++) {
    cin >> c[i].first >> c[i].second;
  }
  for (int i = 0; i < N; i++)
  {
    ll x = s[i].first;
    ll y = s[i].second;
    ll mindis = 9000000000000000000;
    int ans;
    for (int j = 0; j < M; j++)
    {
      ll xd = c[j].first;
      ll yd = c[j].second;
      ll dis = abs(x-xd)+abs(y-yd);
      if(chmin(mindis,dis))ans = j;
    }
    cout << ans+1 << endl;
  }
  
}