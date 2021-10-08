#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  set<char> a;
  string ans = "yes";
  for (int i = 0; i < S.size(); i++){
    if (a.find(S.at(i)) == a.end()){
      a.insert(S.at(i));
    }
    else{
      ans = "no";
      break;
    }
  }
  cout << ans << endl;
}
