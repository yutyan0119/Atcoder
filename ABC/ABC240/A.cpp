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
  int a,b;
  cin >> a >> b;
  if(abs(a-b)==1){
    cout << "Yes" << endl;
    return 0;
  }
  else if(a==10&&b==1){
    cout <<"Yes" << endl;
  }
  else if(b==10&&a==1){
    cout <<"Yes"<<endl;
  }
  else{
    cout <<"No" <<endl;
  }
}