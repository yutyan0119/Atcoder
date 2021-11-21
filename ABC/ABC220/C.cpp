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
  ll N;
  cin >> N;
  ll A[N],sum=0;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    sum+=A[i];
  }
  ll X;cin >>X;
  ll p = X/sum;
  ll k = X%sum;
  ll ans = p*N;
  for (int i = 0; i < N; i++)
  {
    k -= A[i];
    if(k<0){
      ans += i+1;
      break;
    }
  }
  cout << ans << endl;
}