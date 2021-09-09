#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;

struct Node{
  int x, y, rank, parent;
  Node(int x, int y, int parent, int rank)
    : x(x), y(y), parent(parent), rank(rank){}
};

struct Edge{
  int u;
  int v;
  double weight;
  Edge(int u, int v, double weight)
    :u(u), v(v), weight(weight){}
};

double weight(int x1, int y1, int x2, int y2){
  return sqrt(pow((x1-x2), 2) + pow((y1 - y2), 2));
}

bool comp(Edge e1, Edge e2){
  return e1.weight < e2.weight;
}

void make_set(int i, vector<Node> &nodes, vector<int> &x, vector<int> &y){
  nodes.push_back(Node(x[i], y[i], i, 0));
}

int find_parent(int i, vector<Node> &nodes){
  if(i != nodes[i].parent){
    nodes[i].parent = find_parent(nodes[i].parent, nodes);
  }
  return nodes[i].parent;
}

void set_union(int u, int v, vector<Node> &nodes){
  int p1 = find_parent(u, nodes);
  int p2 = find_parent(v, nodes);
  if(p1 != p2){
    if(nodes[p1].rank > nodes[p2].rank){
      nodes[p2].parent = p1;
    }
    else{
      nodes[p1].parent = p2;
      if(nodes[p1].rank == nodes[p2].rank){
        nodes[p2].rank++;
      }
    }
  }
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  int n = x.size();
  vector<Node> nodes;
  vector<Edge> edges;
  for(int i = 0; i < n; i++){
    make_set(i, nodes, x, y);
    // nodes.push_back(Node(x[i], y[i], i, 0));
  }
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      edges.push_back(Edge(i, j, weight(x[i], y[i], x[j], y[j])));
    }
  }

  sort(edges.begin(), edges.end(), comp);

  for(int i = 0; i < edges.size(); i++){
    Edge curr_edge = edges[i];
    int u = curr_edge.u;
    int v = curr_edge.v;
    if(find_parent(u, nodes) != find_parent(v, nodes)){
      result += curr_edge.weight;
      set_union(u, v, nodes);
    }  
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
