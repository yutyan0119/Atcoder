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

ll mod = 998244353;

map<ll,ll> result;

ll solve(ll ans, ll x) {
  if(result.find(x)!=result.end()){
    return result[x];
  }
  if (x <= 4) {
    return x;
  } else {
    if (x % 2 == 0) {
      result[x] = solve(ans, x/2)%mod*solve(ans, x/2)%mod;
      return result[x];
    }
    else{
      result[x] = solve(ans,x/2)%mod*solve(ans,x/2+1)%mod;
      return result[x];
    }
  }
}

int main() {
  ll X;
  cin >> X;
  ll ans = 1;
  cout << solve(ans,X)%mod << endl;
}