#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
  if (a < b) a = b;
}

int main() {
  string s;
  cin >> s;
  unordered_set<char> acgt = {'A', 'C', 'G', 'T'};

  int ans = 0;

  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      string sub_s = s.substr(i, j-i+1);
      bool isacgt = true;
      for (char c: sub_s) {
        if (acgt.count(c) == 0) {
          isacgt = false;
          break;
        }
      }

      if (isacgt == false) continue;

      chmax(ans, (int)sub_s.size());
    }
  }
  cout << ans << endl;
}