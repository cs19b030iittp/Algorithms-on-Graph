#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bfs(vector<vector<int>> &adj, vector<int> &state, int s){
  queue<int> q;
  q.push(s);
  state[s] = 1;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i];
      if(state[v] == state[u]){
        return 0;
      }
      if(state[v] == 0){
        state[v] = -state[u];
        q.push(v);
      }
    }
  }
  return 1;
}

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  vector<int> state(adj.size(), 0);
  for(int i = 0; i < adj.size(); i++){
    if(state[i] == 0){
      if(bfs(adj, state, i) == 0)
        return 0;
    }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
