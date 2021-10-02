#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, B;
  cin >> A >> B;
  int C = A-B;
  int D = 1;
  for (int i = 0; i<C; i++){
    D*=32;
  }
  cout << D << endl;
}