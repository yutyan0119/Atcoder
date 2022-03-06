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

ll powmod(ll a, ll b) {
  if (b == 0) {
    return 1;
  } else if (b == 1) {
    return a % mod;
  } else if (b == 2) {
    return (a * a) % mod;
  } else if (b % 2) {
    return (powmod(powmod(a, b / 2), 2) * a) % mod;
  } else {
    return ((powmod(a, b / 2), 2)) % mod;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll T;
  cin >> T;
  for (ll i = 0; i < T; i++) {
    ll N;
    string S;
    ll ans = 0;
    cin >> N >> S;
    if (N % 2 == 0) {
      for (ll j = 0; j < N / 2; j++) {
        ans += (ll)(S.at(j) - 'A') * powmod(27, (N / 2 - j - 1));
        ans %= mod;
      }
      if (S.at(N / 2) < S.at(N / 2 + 1)) {
        ans++;
      } else if (S.at(N / 2 - 1) == S.at(N / 2)) {
        string S1 = S.substr(0, N / 2);
        string S2 = S.substr(N / 2 );
        cout << S1 << S2 << "\n";
        if (S1 < S2) {
          ans++;
        }
      }
      cout << ans % mod << "\n";
    } else {
      for (ll j = 0; j <= N / 2; j++) {
        ans += (ll)(S.at(j) - 'A') * powmod(27, (N / 2 - j));
        ans %= mod;
      }
      string S1 = S.substr(0, N / 2);
      string S2 = S.substr(N / 2 + 1);
      cout << S1 << S2 << "\n";
      if (S1 <= S2) {
        ans++;
      }
      cout << ans % mod << "\n";
    }
  }
}
