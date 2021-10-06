#include <bits/stdc++.h>
using namespace std;

int main(){
  set <int> s;
  int S;
  cin >> S;
  s.insert(S);
  int cur = S;
  for (int i = 0; i < 1000000; i++)
  {
    int nxt;
    if (cur % 2 == 0) nxt = cur/2;
    else nxt = 3*cur +1;

    if (s.count(nxt)){
      cout << i+2 <<endl;
      return 0;
    }
    s.insert(nxt);
    cur = nxt;
  }
  
}
