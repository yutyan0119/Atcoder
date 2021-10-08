#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,D,X;
  cin >> N >> D >> X;
  int A[N];
  for (int i = 0 ; i < N ; i ++){
    cin >> A[i];
  }
  int def ;
  int choco = 0;
  for (int i = 0; i < N ; i++){
    int j = 0;
    def = A[i];
    while(true){
      j++;
      if (j*def + 1 > D){
        j--;
        break;
      }
    }
    choco += (j+1);
  }
  cout << choco + X << endl;
}