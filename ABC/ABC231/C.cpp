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
  int N,Q;
  cin >> N >> Q;
  ll A[N];
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  sort(A,A+N);
  ll x[Q];
  ll ans[Q];
  for (int i = 0; i < Q; i++)
  {
    cin >> x[i];
    int wa = -1;
    int ac = N;
    while (ac-wa>1){
      int med = (wa+ac)/2;
      if (A[med] >= x[i]){
        ac = med;
      }
      else {
        wa = med;
      }
    }
    ans[i] = N - ac;
  }
  for (int i = 0; i < Q; i++)
  {
    cout << ans[i] << endl;
  }
  
}