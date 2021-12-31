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

typedef long long ll;

/* ---------------------------------------------------*/

int main() {
  int count5 = 0;
  int count7 = 0;
  for (int i = 0; i < 3; i++)
  { 
    int k;
    cin >> k;
    if(k == 5)count5++;
    if(k==7)count7++;
  }
  if(count5 == 2 && count7 == 1){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}