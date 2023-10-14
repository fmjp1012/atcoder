#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> dist;
queue<int> todo;
void bfs(const Graph &G, int s) {
  int n = (int)G.size();
  dist.at(s) = 0;
  todo.push(s);

  while (!todo.empty()) {
    int v = todo.front();
    todo.pop();

    for (auto next_v: G.at(v)) {
      if (dist.at(next_v) != -1) continue;
      dist.at(next_v) = dist.at(v) + 1;
      todo.push(next_v);
    }
  }
}

int main() {
  int n;
  cin >> n;
  Graph G(n);
  dist.assign(n, -1);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v_k;
      cin >> v_k;
      G.at(i).push_back(v_k-1);
    }
  }

  bfs(G, 0);
  for (int i = 0; i < n; i++) cout << i+1 << ' ' << dist.at(i) << endl;
}