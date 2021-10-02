#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >>S;
  sort(S.begin(), S.end(), greater<int>());
  int size = (int)(S.size());
  int s2 = size/2;
  string a,b;
  for (int i = 0; i < s2; i++)
  {
    a.append(1,S.at(i*2));
    b.append(1,S.at(i*2+1));
  }
  if (size %2 == 1){
    b.append(1,S.at(size-1));
  }
  int A = stoi(a);
  int B = stoi(b);
  cout << A*B << endl;
}