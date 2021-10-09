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
  int N;
  int P;
  cin >> N >> P;
  int A[N];
  rep(i, 0 , N){
    cin >> A[i];
  }
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    if (A[i] < P){
      count++;
    }
  }
  cout << count << endl;
}