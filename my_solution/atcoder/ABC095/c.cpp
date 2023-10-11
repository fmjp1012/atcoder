#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
  if (a < b) a = b;
}

template<class T> void chmin(T &a, T b) {
  if (a > b) a = b;
}

int main() {
  long long a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  long long ans = 0;

  if (a+b <= c*2) {
    ans = a*x + b*y;
  } else {
    
    if (x > y) {
      if (a >= c*2) {
        ans = c*2*x;
      } else if (a < c*2) {
        ans = c*2*y + a*(x-y);
      }
    } else if (x < y) {
      if (b >= c*2) {
        ans = c*2*y;
      } else if (b < c*2) {
        ans = c*2*x + b*(y-x);
      }
    } else if (x == y) {
      ans = c * 2 * x;
    }
  }
  
  cout << ans << endl;
}