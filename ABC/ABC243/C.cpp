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

const ll mod = 998244353;

int main() {
  ll N;
  cin >> N;
  vector<ll> X(N);
  vector<pair<ll, ll>> P(N);
  for (ll i = 0; i < N; i++) {
    ll y;
    scanf("%lld%lld", &X[i], &y);
    P[i] = make_pair(y, i);
  }
  string S;
  cin >> S;
  sort(P.begin(), P.end());
  for (ll i = 0; i < N - 1; i++) {
    ll minrx = 1e15;
    ll maxlx = -1;
    ll iter1 = P[i].second;
    ll Yiter1 = P[i].first;
    char a = S.at(iter1);
    if (a == 'L')
      maxlx = X[iter1];
    else if (a == 'R') {
      minrx = X[iter1];
    }
    for (ll j = i + 1; j < N; j++) {
      if (Yiter1 == P[j].first) {
        ll iter2 = P[j].second;
        char b = S.at(iter2);
        if (b == 'L') chmax(maxlx, X[iter2]);
        if (b == 'R') chmin(minrx, X[iter2]);
        i = j - 1;
      } else {
        i = j - 1;
        break;
      }
    }
    if (minrx < maxlx && minrx != (ll)1e15 && maxlx != -1) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
}
