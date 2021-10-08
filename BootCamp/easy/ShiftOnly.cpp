#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  bool can = true;
  int count = 0; 
  while (can){
    int check = 0;
    for (int i = 0 ; i< N; i++){
      if (A[i] % 2 == 0){
        A[i] /= A[i]/2;
      }
      else {
        can = false;
      }
      if (check == N){
        count ++;
      }
    }
  }
  cout << count << endl;
}
