#include <bits/stdc++.h>
using namespace std;
int main () {
  int N, Y,x=-1, y=-1, z=-1;
  cin >> N >> Y;
  if (10000*N >= Y){
    for (int i=0 ; i<N+1; i++){
      int M=N-i;
      for (int j=0; j<M+1;j++){
        int L = M-j;
        for (int k=0 ; k < L+1; k++){
          int sum = 10000*i + 5000*j + 1000*k;
          if (i + j + k == N &&sum == Y){
            x = i;
            y = j;
            z = k;
          }
        }
      }
    }
  }
  cout << x <<" "<< y <<" "<< z << endl;
}