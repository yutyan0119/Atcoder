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
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll T;
  cin >> T;
  for (ll i = 0; i < T; i++) {
    ll N;
    string S;
    cin >> N >> S;
    ll count = 0;
    string target = S;
    int p = 0, q = N - 1;
    while (p < q) {
      target[q] = target[p];
      p++;
      q--;
    }
    int last = (N - 1) / 2;
    for (int j = 0; j <= last; j++) {
      count *= 26;
      count %= mod;
      count += (S[j] - 'A');
      count %= mod;
    }
    count++;
    count %= mod;
    if (S < target) {
      count += (mod - 1);
      count %= mod;
    }
    cout << count << "\n";
  }
}
