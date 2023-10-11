#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
  if (a < b) a = b;
}

template<class T> void chmin(T &a, T b) {
  if (a > b) a = b;
}

int main() {
  long long n;
  string s;
  cin >> n >> s;
  int ans = 0;

  for (int i = 0; i <= 999; i++) {
    string temp = "";
    if (i < 10) temp += "00";
    else if (i < 100) temp += "0";
    temp += to_string(i);

    int a, b, c;
    a = find(s.begin(), s.end(), temp.at(0)) - s.begin();
    if (a != (int)s.size()) {
      b = find(s.begin() + a + 1, s.end(), temp.at(1)) - s.begin();
      if (b != (int)s.size()) {
        c = find(s.begin() + b + 1, s.end(), temp.at(2)) - s.begin();
        if (c != (int)s.size()) {
          ans++;
        }
      }
    }

  }
  cout << ans << endl;
}