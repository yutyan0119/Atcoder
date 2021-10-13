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
  int A, B, count = 0;
  cin >> A >> B;
  for (int i = A; i < B+1 ; i++)
  { int s = i%10;
    int t = i/10000 %10;
    int u = i/10 %10;
    int v = i/1000 %10;
    if (s ==t && u==v){
      count ++;
    }
  }
  cout << count << endl;
}