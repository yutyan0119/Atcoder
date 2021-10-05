#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C, count = 0;
  cin >> A >> B >> C;
  int iniA = A,iniB = B,iniC = C;
  while ( A%2 == 0 && B%2 == 0 && C%2 == 0)
  {
    int At = A;
    int Bt = B;
    int Ct = C;
    A = Bt/2 + Ct/2;
    B = At/2 + Ct/2;
    C = At/2 + Bt/2;
    count ++;
    if (A == iniA && B == iniB && C == iniC) {
      count = -1;
      break;
    } 
  }
  cout << count << endl;
}