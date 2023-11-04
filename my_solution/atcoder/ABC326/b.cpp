#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = n; i < 1000; i++) {
    int h, j, temp;
    temp = i;
    h = temp / 100;
    temp %= 100;
    j = temp / 10;
    temp %= 10;
    if (h * j == temp) {
      cout << i << endl;
      break;
    }
  }

}