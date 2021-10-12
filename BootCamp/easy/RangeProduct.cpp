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
  int a,b;
  cin >> a >> b;
  if(a>0 && b>0){
    cout << "Positive" << endl;
  }
  else if ((a<0 && b>0) || (a==0 || b==0)){
    cout << "Zero" << endl;
  }
  else if (a<0 && b<0 && (b-a)%2 == 0){
    cout << "Negative" << endl;
  }
  else cout << "Positive" << endl;
}