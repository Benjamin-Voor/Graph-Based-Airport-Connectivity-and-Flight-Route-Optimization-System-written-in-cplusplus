#ifndef TASK_3_H
#define TASK_3_H

#include "Graph.cpp"
#include "Graph.h"
#include "Vertex.h"
#include "Queue.h"
#include "Queue.cpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

// Task 3: Find all shortest paths between the given origin airport and all the airports in the destination state. The algorithm should output all the paths and their lengths. The algorithm should provide the appropriate message if no such paths exist. 

void dijkstra_shortest_path(Graph<std::string> &airports, Vertex<std::string> src, Vertex<std::string> dst);

void task_3(Graph<std::string> &airports, std::string origin, std::string destinationState) {
  Vertex<std::string> originVertex = airports.getVertex(origin);
  // find all the destination state airports and add them to an array
  std::vector<Vertex<std::string>> *destination_state_airports;
  for(Vertex<std::string> arp : airports.getVertices()){
    if(arp.getState() == destinationState){
      destination_state_airports->push_back(arp);
    }
  }
  
  // Use a modified Dijkstra's algorithm that does not stop after finding the shortest path for each destination state airport
  cout << "Path" << setw(5) << "Length" << setw(5) << "Cost" << endl;
  for(Vertex<std::string> dst : *destination_state_airports) {
    dijkstra_shortest_path(airports, originVertex, dst);
    cout << endl;
  }
}

void dijkstra_shortest_path(Graph<std::string> &airports, Vertex<std::string> &src, Vertex<std::string> &dst){
  int i_src = airports.get_vertex_index(src);
  int i_dest = airports.get_vertex_index(dst);

  if (i_src == -1 || i_dest == -1) {
    throw std::string("Shortest path: incorrect vertices");
  }
  std::vector<Vertex<std::string>> vertices = airports.getVertices();
  std::vector<std::vector<Edge>> edges = airports.getEdges();

  airports.clean_visited();
  std::vector<int> distances(
      vertices.size()); // represents the distances from
                                      // source to all other vertices
  // set initial distances
  for (int i = 0; i < distances.size(); i++) {
    distances[i] =
        (i == i_src) ? 0 : INT_MAX; // 0 if source, infinite otherwise
  }

  MinHeap<Edge> heap;       // used to store edges
  int vertices_visited = 0; // tracks number of vertices visited
  int cur_ver = i_src;      // current vertex index

  while (vertices_visited < vertices.size()) { // until all vertices are visited
    int i = cur_ver;
    // check the neighbours of the current node
    for (int j = 0; j < edges[i].size();
         j++) { // iterates over adjacent vertices of current vertex
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

  airports.clean_visited();

  std::cout << distances[i_dest];
}

#endif