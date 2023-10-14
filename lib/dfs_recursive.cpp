#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

struct Edge {
  int to;
  int w;
  Edge(int to, int w) : to(to), w(w) {}
};

vector<bool> seen;
void dfs(const Graph &G, int v) {
  int n = (int)G.size();
  vector<bool> seen(n, false);

  // 行きがけ

  for (auto next_v: G.at(v)) {
    if (seen.at(next_v)) continue;
    dfs(G, next_v);
  }

  // 帰りがけ
}

int main() {
  // seen.assign(n, false);
}