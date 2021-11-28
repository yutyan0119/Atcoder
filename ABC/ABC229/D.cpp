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
  string A;
  string B;
  cin >> A >> B;
  reverse(A.begin(),A.end());
  reverse(B.begin(),B.end());
  for (int i = 0; i<min(A.size(),B.size());i++)
  {
    if (A.at(i)-'0' + B.at(i)-'0' >= 10){
      cout << "Hard" << endl;
      return 0;
    }
  }
  cout << "Easy" << endl;
}