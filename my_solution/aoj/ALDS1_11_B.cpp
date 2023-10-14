#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> d, f;
vector<bool> seen;
int t = 1;
void dfs(const Graph &G, int v) {
  int n = (int)G.size();
  seen.at(v) = true;
  d.at(v) = t;
  t++;

  for (auto next_v: G.at(v)) {
    if (seen.at(next_v)) continue;
    dfs(G, next_v);
  }

  f.at(v) = t;
  t++;
}

int main() {
  int n;
  cin >> n;
  Graph G(n);
  d.assign(n, -1);
  f.assign(n, -1);
  seen.assign(n, false);

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v_k;
      cin >> v_k;
      G.at(i).push_back(v_k - 1);
    }
  }

  for (int i = 0; i < n; i++) {
    if (seen.at(i)) continue;
    dfs(G, i);
  }

  for (int i = 0; i < n; i++) {
    cout << i+1 << ' ' << d.at(i) << ' ' << f.at(i) << endl;
  }
}