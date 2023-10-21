#include <bits/stdc++.h>
using namespace std;
const long long INF = (1 << 30);
using Graph = vector<vector<int>>;

vector<vector<int>> dist;
queue<pair<int, int>> todo;
vector<vector<bool>> table;
int ans = 0;
void bfs(pair<int, int> s) {
  dist.at(s.first).at(s.second) = 0;
  todo.push(s);
  while (!todo.empty()) {
    pair<int, int> v;
    v = todo.front();
    todo.pop();

    if (table.at(v.first-1).at(v.second) && dist.at(v.first-1).at(v.second) == INF) {
      todo.push(make_pair(v.first-1, v.second));
      dist.at(v.first-1).at(v.second) = dist.at(v.first).at(v.second) + 1;
    }
    if (table.at(v.first).at(v.second+1) && dist.at(v.first).at(v.second+1) == INF){
      todo.push(make_pair(v.first, v.second+1));
      dist.at(v.first).at(v.second+1) = dist.at(v.first).at(v.second) + 1;
    }
    if (table.at(v.first+1).at(v.second) && dist.at(v.first+1).at(v.second) == INF){
      todo.push(make_pair(v.first+1, v.second));
      dist.at(v.first+1).at(v.second) = dist.at(v.first).at(v.second) + 1;
    }
    if (table.at(v.first).at(v.second-1) && dist.at(v.first).at(v.second-1) == INF) {
      todo.push(make_pair(v.first, v.second-1));
      dist.at(v.first).at(v.second-1) = dist.at(v.first).at(v.second) + 1;
    }
  }
}

int main() {
  int r, c;
  cin >> r >> c;
  pair<int, int> start, goal;
  cin >> start.first >> start.second >> goal.first >> goal.second;
  start.first--;
  start.second--;
  goal.first--;
  goal.second--;

  table.assign(r, vector<bool>(c, false));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char temp;
      cin >> temp;
      if (temp == '.') table.at(i).at(j) = true;
    }
  }


  dist.assign(r, vector<int>(c, INF));

  bfs(start);

  cout << dist.at(goal.first).at(goal.second) << endl;
}