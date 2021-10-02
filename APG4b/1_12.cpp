#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S ;
  int n = (int)(S.size());
  int plus = 0, minus = 0;
  for (int i = 0; i < n; i++)
  {
    if ( S.at(i) == '+' ){
      plus ++;
    }
    else if ( S.at(i) == '-'){
      minus ++;
    }
  }
  cout << 1 + plus - minus <<endl;
}