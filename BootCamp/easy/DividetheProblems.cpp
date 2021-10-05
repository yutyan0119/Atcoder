#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  int d[N];
  for (int i = 0; i < N; i++)
  {
    cin >> d[i];
  }
  sort (d,d+N);
  int A = d[N/2 -1];
  int B = d[N/2];
  cout << B-A << endl;
}