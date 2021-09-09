#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int x, stack<int> &s){
  visited[x] = true;
  for(int i = 0; i < adj[x].size(); i++){
    if(!visited[adj[x][i]]){ 
      dfs(adj, visited, adj[x][i], s);
    }
  }
  s.push(x);
}


int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  vector<vector<int>> rAdj(adj.size(), vector<int>());    // reverse graph
  vector<bool> visited(adj.size(), false);
  stack<int> s;
  for(int i = 0; i < adj.size(); i++){
    for(int j = 0; j < adj[i].size(); j++){
      rAdj[adj[i][j]].push_back(i);
    }
  }

  for(int i = 0; i < rAdj.size(); i++){
    if(!visited[i]){
      dfs(rAdj, visited, i, s);
    }
  }

  std::fill(visited.begin(), visited.end(), false);

  while(!s.empty()){
    int x = s.top();
    s.pop();
    if(!visited[x]){
      stack<int> cStack;
      dfs(adj, visited, x, cStack);
      result++;
    }
  }

  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  // vector<vector<int> > adj(4, vector<int>()); adj = {{1},{2},{0},{0}};
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
