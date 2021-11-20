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

ll GCD(ll a, ll b) {
  if (a < b) {
    swap(a, b);
  }
  ll k = a % b;
  while (k > 0) {
    a = b;
    b = k;
    k = a % b;
  }
  return b;
}

vector<pair<ll, ll>> enumpr(ll n) {
  vector<pair<ll, ll>> V;
  for (ll i = 2; i * i < n; i++) {
    if (n%i!=0)continue;
    ll ex = 0;
    while (n % i == 0) {
      ex++;
      n /= i;
    }
    V.push_back({i, ex});
  }
  if (n != 1) {
    V.push_back({n,1});
  }
  return V;
}
int main() {
  ll A, B;
  cin >> A >> B;
  ll gcd = GCD(A, B);
  auto element = enumpr(gcd);
  cout << element.size() + 1 << endl;
}