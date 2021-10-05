#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,K;
  cin >> N >> K;
  long long t = N % K;
  if ( t < K-t) N = t;
  else N = K-t;
  cout << N << endl;
}