#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  while (true)
  {
    for (int i = 1; i < X; i++)
    {
      if (X % i ==0 && i != 1){
        break;
      }
      else if (i == X-1){
        cout << X << endl;
        return 0;
      }
    }
    X++;
  }
}
