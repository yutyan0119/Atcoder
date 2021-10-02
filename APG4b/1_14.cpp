#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,tall,mtall;
  cin >> a >> b >> c ;
  tall = max (c, max (a,b));
  mtall = min (c, min (a,b));
  cout << tall - mtall << endl;
}