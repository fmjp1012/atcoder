#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<char> v, v_prev;

  for (char c: s) {
    v.push_back(c);
  }


  v_prev = v;
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  if (v == v_prev) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
