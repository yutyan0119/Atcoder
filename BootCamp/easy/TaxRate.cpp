#include <bits/stdc++.h>
using namespace std;
int main(){
  double N;
  cin >>N;
  double X;
  X = N/1.08;
  int Y = (int)X;
  if ((int)Y * 1.08 == N)  cout << Y << endl;
  else if ((int)((Y+1) * 1.08) == N) cout << Y+1 <<endl;
  else if ((int)((Y-1) * 1.08) == N ) cout << Y-1 << endl;
  else{
    cout << ":(" << endl;
  }
}