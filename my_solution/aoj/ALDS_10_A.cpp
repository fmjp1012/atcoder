#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> fib(n+1);

  fib.at(0) = 1;
  fib.at(1) = 1;
  
  for (int i = 2; i <= n; i++) {
    fib.at(i) = fib.at(i-1) + fib.at(i-2);
  }

  cout << fib.at(n) << endl;
}