#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for(int i = s; i <e ; i++)

/* ---------------------------------------------------*/

int main() {
  int N,M;
  cin >> N >> M;
  vector <vector<int>> A(N,vector<int>(M,0));
  rep(i, 0, N) {
    int k; 
    cin >> k;
    rep(j, 0, k) {
      int a; 
      cin >> a;
      a--;
      A[i][a]=1;
      }
  }
 
  int ans = 0;  
  rep(i, 0, M) {
    int count=0;
    rep(j,0,N) {
      if (A[j][i] == 1) count ++;
    }
    if (count == N) ans ++;
  }
  cout << ans << endl;
}