#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  int n = adj.size();
  vector<int> d(adj.size(), n);
  queue<int> q;
  d[s] = 0;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i = 0; i < adj[u].size(); i++){
      if(d[adj[u][i]] == n){
        d[adj[u][i]] = d[u] + 1;
        q.push(adj[u][i]);
      }
    }
  }
  if(d[t] != n){
    return d[t];
  }
  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
