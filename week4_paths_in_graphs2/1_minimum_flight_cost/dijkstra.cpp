#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  vector<long long> min_cost(adj.size(), std::numeric_limits<long long>::max());
  priority_queue<pair<long long,int>, vector<pair<long long,int>>, std::greater<pair<long long,int>>> q;
  min_cost[s] = 0;
  q.push(std::make_pair(min_cost[s], s));
  while(!q.empty()){
    int u = q.top().second;
    q.pop();
    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i];
      if(min_cost[v] > min_cost[u] + cost[u][i]){
        min_cost[v] = min_cost[u] + cost[u][i];
        q.push(std::make_pair(min_cost[v], v));
      } 
    }
  }
  if(min_cost[t] != std::numeric_limits<long long>::max()) return min_cost[t];
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
