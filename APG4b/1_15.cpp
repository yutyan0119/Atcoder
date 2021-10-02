#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, asum=0, bsum=0, csum=0;
  cin >> N;
  vector <int> a(N);
  vector <int> b(N);
  vector <int> c(N);
  for (int i = 0; i < N; i++)
  { 
    cin >> a.at(i);
    asum += a.at(i);
  }
  for (int i = 0; i < N; i++)
  { 
    cin >> b.at(i);
    bsum += b.at(i);
  }
  for (int i = 0; i < N; i++)
  { 
    cin >> c.at(i);
    csum += c.at(i);
  }
  cout << asum * bsum * csum << endl;
}