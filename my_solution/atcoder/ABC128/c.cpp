#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
  if (a < b) a = b;
}

template<class T> void chmin(T &a, T b) {
  if (a > b) a = b;
}

int main() {
  int n, m;
  cin >> n >> m;

  int k;
  vector<vector<int>> nm(n);

  for (int i=0; i<m; i++) {
    cin >> k;
    for (int j=0; j<k; j++) {
      int s_temp;
      cin >> s_temp;
      nm.at(s_temp-1).push_back(i);
    }
  }

  int ans = 0;
  vector<int> p(m);
  for (int i=0; i<m; i++) cin >> p.at(i);

  for (int i=0; i<(1<<n); i++) {
    bitset<10> s(i);

    vector<int> cnt(m);
    for (int j=0; j<n; j++) {
      if (s.test(j)) {
        for (auto x: nm.at(j)) {
          cnt.at(x)++;
        }
      }
    }

    bool flag = true;
    for (int j=0; j<m; j++) {
      cnt.at(j) %= 2;
      if (cnt.at(j) != p.at(j)) {
        flag = false;
        break;
      }
    }

    if (flag) ans ++;
  }

  cout << ans << endl;
}