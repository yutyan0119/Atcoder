#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  set <char> alphabet;
  string ans = "None";
  for (int i = 0; i < (int)S.size(); i++)
  {
    alphabet.insert(S.at(i));
  }
  for (char i = 'a'; i < 'z'+1; i++)
  {
    if (alphabet.find(i) == alphabet.end()){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
