#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x;
  cin >> N >> x;
  int a[N];
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  sort(a, a+N);
  int cur = x;
  int count = 0;
  int i = 0;
  while (cur >= 0 && i < N)
  { cur = cur - a[i];
    if (cur >= 0){
      count ++;
      i++;
    }
    else break;
  }
  cout << count << endl;
}
