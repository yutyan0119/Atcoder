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
  ll N, W;
  cin >> N >> W;
  vector <pair<ll,ll>> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  ll oisisa = 0;
  sort(A.begin(),A.end(),greater<pair<ll,ll>>());
  ll weight = 0;
  for (ll i = 0; i < N; i++)
  {
    if (weight >= W){
      break;
    }
    if (weight + A[i].second <= W){
      oisisa += A[i].first*A[i].second;
      weight += A[i].second;
    }else {
      oisisa += A[i].first*(W-weight);
      weight += W-weight;
      break;
    }
  }
  cout << oisisa << endl;
}