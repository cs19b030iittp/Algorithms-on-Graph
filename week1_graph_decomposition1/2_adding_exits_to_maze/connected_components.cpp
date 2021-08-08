#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int>> &adj, vector<bool> &visited, int s){
  visited[s] = true;
  for(int i = 0; i < adj[s].size(); i++){
    if(visited[adj[s][i]] == false){
      explore(adj, visited, adj[s][i]);
    }
  }
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  vector<bool> visited(adj.size(), false);
  for(int i = 0; i < adj.size(); i++){      // checking rows
    if(visited[i] == false){
      explore(adj, visited, i);
      res++;
    }
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
