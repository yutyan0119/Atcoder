#include <bits/stdc++.h>
using namespace std;
int main(){
  int A[3][3];
  for (int i = 0; i<3 ;i++){
    for (int j =0; j<3; j++){
      cin >> A[i][j];
    }
  }
  int N;
  cin >> N;
  int b[N];
  for (int i = 0; i < N; i++)
  {
    cin >> b[i];
  }
  bool appear[3][3];
  bool bingo = false;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      appear[i][j]=false;
      for (int k = 0; k<N ; k++){
        if (A[i][j] == b[k]) appear[i][j] = true;
      }
    }
    
  }
  string ANS = "No";
  for (int i = 0; i < 3; i++)
  {
    if (appear [i][0] && appear[i][1] && appear[i][2]) ANS = "Yes";
    if (appear[0][i] && appear [1][i] && appear[2][i]) ANS = "Yes";
  }
  if (appear[0][0] && appear[1][1] && appear[2][2]) ANS = "Yes";
  if (appear[0][2] && appear[1][1] && appear[2][0]) ANS = "Yes";
  cout << ANS << endl;
  
}