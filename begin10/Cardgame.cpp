#include <bits/stdc++.h>
using namespace std;
int main () {
  int N, Alice=0, Bob=0;
  cin >> N ;
  vector <int> a(100, 0);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i]; 
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int i = 0; i < 50; i++)
  {
    Alice += a.at(i*2);
    Bob += a.at(i*2+1);
  }
  cout << Alice -Bob << endl;
}