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
  string S;
  cin >> S;
  string A((int)S.size(),'0'),B((int)S.size(),'0');
  for (int i = 0; i < (int)S.size(); i++)
  {
    if (i%2 == 0){
      A.at(i) = '0';
      B.at(i) = '1';
    }
    else {
      A.at(i) = '1';
      B.at(i) = '0';
    }
  }
  int ans;
  int cntA = 0;
  int cntB = 0;
  for (int i = 0; i < (int)S.size(); i++)
  {
    cntA += abs(A.at(i)-S.at(i));
    cntB += abs(B.at(i)-S.at(i));
  }
  ans = min(cntA,cntB);
  cout << ans << endl;
}