#include "Graph.h"
#include "MinHeap.cpp"
#include "MinHeap.h"

#include <iostream>
#include "Queue.h"
#include <unistd.h>
#define INT_MAX 1000

template <typename T> void Graph<T>::insert_vertex(const Vertex<T> &ver) {
  if (get_vertex_index(ver) == -1) {
    vertices.push_back(ver); // insert the vertex to the array of vertices
    std::vector<Edge> tmp;
    edges.push_back(tmp); // insert empty vector to the edges
  }
}

template <typename T> int Graph<T>::get_vertex_index(const Vertex<T> &ver) {
  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i].getData() == ver.getData()) {
      return i;
    }
  }

  return -1;
}

template <typename T>
void Graph<T>::add_edge(const Vertex<T> &src, const Vertex<T> &dest,
                        int distance, int cost) { 
  // Ben renamed vertices ver1, ver2 to src, dest
  int i1 = get_vertex_index(src);
  int i2 = get_vertex_index(dest);
  if (i1 == -1 || i2 == -1) {
    throw std::string("Add_edge: incorrect vertices");
  }
  Edge v(i1, i2, distance, cost);
  /* Edge v2(i2, i1, distance); // This converts a directed graph to an undirected graph
  edges[i1].push_back(v);
  if (i1 != i2) {
    edges[i2].push_back(v2);
  }
  */
}

template <typename T> void Graph<T>::print() const {
  for (int i = 0; i < vertices.size(); i++) {
    std::cout << "{ " << vertices[i].getData() << ": ";
    for (int j = 0; j < edges[i].size(); j++) {
      std::cout << '{' << vertices[edges[i][j].dest].getData() << ", ";
      std::cout << edges[i][j].distance << "} ";
    }
    std::cout << " }\n";
  }
}

template <typename T> void Graph<T>::DFS(Vertex<T> &ver) {
  clean_visited();
  DFS_helper(ver);
  clean_visited();
}

template <typename T> void print_queue(Queue<Vertex<T>> q) {
  while (!q.empty()) {
    std::cout << q.front().getData() << " ";
    q.pop();
  }
  std::cout << std::endl;
}

template <typename T> void Graph<T>::BFS(Vertex<T> &ver) {
  clean_visited();

  int i = get_vertex_index(ver);
  if (i == -1) {
    throw std::string("BFS: Vertex is not in the graph");
  }
  Queue<int> q;
  q.push(i);
  vertices[i].setVisited(true);

  while (!q.empty()) {
    int i = q.front();
    std::cout << vertices[i].getData() << ' ';
    for (int j = 0; j < edges[i].size(); j++) {
      int adjacent_ver = edges[i][j].dest;
      if (vertices[adjacent_ver].getVisited() == false) {
        vertices[adjacent_ver].setVisited(true);
        q.push(adjacent_ver);
      }
    }
    q.pop();
  }

  clean_visited();
}

template <typename T> void Graph<T>::clean_visited() {
  for (Vertex<T> &v : vertices) {
    v.setVisited(false);
  }
}

template <typename T> void Graph<T>::DFS_helper(Vertex<T> &ver) {
  int i = get_vertex_index(ver);
  if (i == -1) {
    throw std::string("DFS: Vertex is not in the graph");
  }
  vertices[i].setVisited(true); // visit the current vertex
  std::cout << vertices[i].getData()
            << ' '; // print the data of the current vertex
  for (int j = 0; j < edges[i].size(); j++) {
    Vertex<int> adjacent_ver = vertices[edges[i][j].dest];
    if (adjacent_ver.getVisited() == false) {
      DFS_helper(adjacent_ver);
    }
  }
}

template <typename T>
int Graph<T>::dijkstra_shortest_path(const Vertex<T> &src,
                                     const Vertex<T> &dest) {
  int i_src = get_vertex_index(src);
  int i_dest = get_vertex_index(dest);

  if (i_src == -1 || i_dest == -1) {
    throw std::string("Shortest path: incorrect vertices");
  }

  clean_visited();
  std::vector<int> distances(vertices.size()); // represents the distances from
                                               // source to all other vertices

  // set initial distances
  for (int i = 0; i < distances.size(); i++) {
    distances[i] = (i == i_src) ? 0 : INT_MAX; // 0 if source, infinite otherwise
  }

  MinHeap<Edge> heap; // used to store edges
  int vertices_visited = 0; // tracks number of vertices visited
  int cur_ver = i_src; // current vertex index

  while (vertices_visited < vertices.size()) { // until all vertices are visited
    int i = cur_ver;
    // check the neighbours of the current node
    for (int j = 0; j < edges[i].size(); j++) { // iterates over adjacent vertices of current vertex
      int i_adjacent_ver = edges[i][j].dest;
      if (vertices[i_adjacent_ver].getVisited() == false) {
        heap.insert(edges[i][j]);
        int dist_from_source = distances[i] + edges[i][j].distance;
        if (dist_from_source < distances[i_adjacent_ver]) {
          distances[i_adjacent_ver] = dist_from_source;
          // test how the distances change
          for (int i : distances) {
            std::cout << i << ' ';
          }
          std::cout << '\n';
        }
      }
    }
    Edge e = heap.delete_min();
    cur_ver = e.dest;
    vertices[i].setVisited(true);
    vertices_visited++;
  }

  clean_visited();

  return distances[i_dest];
}

Vertex<std::string> getVertex(std::string name) {
  for(int i = 0; i < airports.vertices.size(); i++) {
    if(airports.vertices[i].getData() == origin) {
      Vertex<std::string> originVertex = airports.vertices[i];
    }
  }
}