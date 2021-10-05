#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, Ans, mcount=0;
  cin >> N ;
  for (int i = 1; i < N+1; i++)
  { int count = 0;
    int j = i;
    while (true)
    {
      if (j%2 == 0){
        j = j/2;
        count ++;
      }
      else break;
    }
    if (count >= mcount){
      mcount = count;
      Ans = i;
    }
  }
  cout << Ans << endl;
}