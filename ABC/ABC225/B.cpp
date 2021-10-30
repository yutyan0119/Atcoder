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

/* ---------------------------------------------------*/

int main() {
  int N;
  cin >> N;
  int a[N-1], b[N-1];
  for (int i = 0; i < N-1; i++)
  {
    cin >> a[i] >> b[i];
  }
  
  int k = a[0];
  int l = b[0];
  int countk = 0;
  int countl = 0;
  for (int i = 1; i < N-1; i++)
  {
    if (a[i]==k||b[i]==k){
      countk ++;
    }
    if (b[i] == l || a[i] == l){
      countl ++;
    }
  }
  if (countk == N-2||countl == N-2){
    cout << "Yes" << endl;
  }else cout << "No" << endl;
}