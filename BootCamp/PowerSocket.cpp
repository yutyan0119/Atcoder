#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  int b;
  int c = 0;
  int d = 1; //aは口数, bは必要口数, cはタップ数, dは合計口数
  cin>> a >> b;
  while (b > d)
  { 
    c+=1;
    d = 1+(a-1)*c;
  }
  cout<< c << endl;
}