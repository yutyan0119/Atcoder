#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin >> N >> K;
  int x[N];
  for (int i = 0; i < N; i++)
  {
    cin >> x[i] ;
  }
  int sum =0;
  for (int i =0 ; i<N; i++){
    sum += min(x[i], abs(K-x[i]))*2;
  }
  cout << sum << endl;
}