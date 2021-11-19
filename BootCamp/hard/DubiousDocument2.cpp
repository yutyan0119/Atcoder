#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

#define rep(i, s, e) for (int i = s; i < e; i++)
#define rrep(i, s, e) for (int i = s; i >= e; i--)

typedef long long ll;

/* ---------------------------------------------------*/

string SS, T;
//---------------------------------------------------------------------------------------------------
string solve() {
    int N = SS.length();
    int M = T.length();
 
    set<string> ans;
    rrep(R, N, M) {
        int L = R - M;
 
        int ok = 1;
        rep(i, 0, M) if (SS[L + i] != '?' and SS[L + i] != T[i]) ok = 0;
        if (ok) {
            string S;
            rep(i, 0, N) S += SS[i];
            rep(i, 0, M) S[L + i] = T[i];
            rep(i, 0, N) if (S[i] == '?') S[i] = 'a';
            ans.insert(S);
        }
    }
 
    if(ans.size() == 0) return "UNRESTORABLE";
    return *(ans.begin());
}
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> SS >> T;
    cout << solve() << endl;
    return 0;
}