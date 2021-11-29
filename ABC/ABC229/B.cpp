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

#define rep(i1, s, e) for (int i1 = s; i1 < e; i1++)

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  string S;
  int K;
  cin >> S >> K;
  int N = (int)S.size();
  vector<int> ss(N);
  for (int i = 0; i < N; i++) {
    ss.at(i) = (S.at(i) == '.'?1:0);
  }
  ll ans = 0;
  ll r = 0;
  ll sum = 0;
  for (ll l = 0; l < N; l++)
  {
    while (r < N && sum+ss[r] <= K)
    { 
      sum += ss.at(r);
      r++;
    }
    ans = max(ans,r-l);
    sum -= ss.at(l);
  }
  cout << ans << endl;
}