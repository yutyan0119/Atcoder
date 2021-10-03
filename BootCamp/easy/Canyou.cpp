#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,C;
  int count = 0;
  cin >> N >> M >> C;
  int B[M], A[N][M];
  for (int i = 0 ; i< M ; i++){
    cin >> B[i];
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> A[i][j]; 
    }
  }

  for (int i = 0; i < N; i++){
    int sum = 0;
    for (int j = 0; j < M; j++){
      sum += A[i][j]*B[j];
      if ( j == M-1 && sum + C > 0){
        count ++;
      } 
    }
  }
  cout << count << endl;
}