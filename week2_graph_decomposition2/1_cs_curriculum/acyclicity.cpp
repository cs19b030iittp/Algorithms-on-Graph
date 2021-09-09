#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool dfs(vector<vector<int>> &adj, int s, vector<bool> &visited, vector<bool> &recStack){
  visited[s] = true;
  recStack[s] = true;
  for(int i = 0; i < adj[s].size(); i++){
    if(!visited[adj[s][i]]){
      if(dfs(adj, adj[s][i], visited, recStack))
        return true;
    }
    else if(recStack[adj[s][i]] == true) 
      return true;
  }
  recStack[s] = false;
  return false;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<bool> visited(adj.size(), false);
  vector<bool> recStack(adj.size(), false);
  for(int i = 0; i < adj.size(); i++){
    if(!visited[i]){
      if(dfs(adj, i, visited, recStack))
        return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
