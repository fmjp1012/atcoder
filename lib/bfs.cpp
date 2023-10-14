#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

struct Edge {
  int to;
  int w;
  Edge(int to, int w) : to(to), w(w) {}
};

void dfs(Graph &G, int s) {
  int n = (int)G.size();
  vector<bool> seen(n, false);
  queue<int> todo;

  seen.at(s) = true;
  todo.push(s);

  while (!todo.empty()) {
    int v = todo.front();
    todo.pop();

    for (auto x: G.at(v)) {
      
      if (seen.at(x) == true) continue;

      seen.at(x) = true;
      todo.push(x);
    }

  }
}

int main() {

}