#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int x[N];
  int P;
  int sum;
  for (int i = 0; i < N; i++)
  {
    cin >> x[i];
  }
  for (int i = 0; i < 101; i++)
  { int tmp = 0;
    P = i;
    for (int j = 0; j < N; j++)
    {
      tmp += (x[j]-P)*(x[j]-P);
    }
    if (i == 0){
      sum = tmp;
    }
    else if (sum > tmp){
      sum = tmp;
    }
  }
  cout << sum << endl;
}