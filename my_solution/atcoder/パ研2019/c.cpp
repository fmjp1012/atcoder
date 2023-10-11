#include <bits/stdc++.h>
using namespace std;

template<class T> void chmax(T &a, T b) {
  if (a < b) a = b;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<long long>> table(n, vector<long long>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> table.at(i).at(j);
    }
  }

  long long ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = i+1; j < m; j++) {
      long long temp = 0;
      for (int k = 0; k < n; k++) {
        temp += max(table.at(k).at(i), table.at(k).at(j));
      }
      chmax(ans, temp);
    }
  }
  cout << ans << endl;
}