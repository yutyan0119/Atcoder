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
  int N, M;
  cin >> N >> M;
  int A[M], B[M], max = 0;
  rep(i,0,M){
    cin >> A[i] >> B[i];
  }
  int K;
  cin >> K;
  int C[K], D[K];
  rep(i,0,K){
    cin >> C[i] >> D[i];
  }

  for (int bit = 0; bit < (1<<K); bit++){
    vector <bool> Dish(N,false);
    int count =0;
    for (int j = 0; j < K; j++){
      if( 1 & bit>>j){
        Dish[D[j]]=true;
      }
      else Dish[C[j]]=true;
    }
    for ( int i = 0; i < M; i++){
      if (Dish[A[i]] && Dish[B[i]]){
        count++;
      }
    }
    chmax(max,count);
  }
  cout << max << endl;
}