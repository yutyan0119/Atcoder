#include <bits/stdc++.h>
using namespace std;
int main () {
  int N,count =1;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  sort(a,a+N);
  for (int i = 0; i < N; i++)
  {
    int b = a[i];
    for (int j = 0; j < i; j++){
      if (b == a[j]){
        break;
      }
      if (j==i-1){
        count+=1;
      }
    }
  }
  cout<< count <<endl;
}