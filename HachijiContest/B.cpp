#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------------------------*/

int main() {
  float a, b, x;
  cin >> a >> b >> x;
  if (a - b >= x + 0.1) {
    cout << "Dangerous" << endl;
    return 0;
  } else {
    cout << "Safe" << endl;
    return 0;
  }
}