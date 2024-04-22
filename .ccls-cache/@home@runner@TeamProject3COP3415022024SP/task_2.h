#ifndef TASK_2_H
#define TASK_2_H
#include "Graph.h"
#include "MinHeap.h"
#include "Vertex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
//#include <climits>

#define INT_MAX 1000

using namespace std;

/*
TAKE 3 PARAMETERS – GRAPH, SRC, DEST

FIND SHORTEST PATH FROM SRC TO DEST IN DIST

FIND NODES ON THAT PATH

PRINT PATH WITH NODES

SUM UP THE TOTAL DISTANCE OF EACH EDGE

SUM UP THE TOTAL COST OF EACH EDGE

  */

void dijkstra(Graph<std::string> airports, Vertex<std::string> src,
              Vertex<std::string> dst) {

  // set initial distances
  int i_src = airports.get_vertex_index(src);
  int i_dest = airports.get_vertex_index(dst);

  // if src or dest is not in the graph
  if (i_src == -1 || i_dest == -1) {
    throw std::string("Shortest path: incorrect vertices");
  }

  // make variables for vertices and edges in airports
  std::vector<Vertex<std::string>> vertices = airports.getVertices();
  std::vector<std::vector<Edge>> edges = airports.getEdges();

  // clean visited
  airports.clean_visited();
  // make a distances vector
  std::vector<int> distances(vertices.size());
  // make a costs vector
  std::vector<int> costs(vertices.size());

  // set initial distances
  for (int i = 0; i < distances.size(); i++) {
    distances[i] = (i == i_src) ? 0 : INT_MAX;
  }

  // create Edge heap and insert all edges
  MinHeap<Edge> heap;
  for (int i = 0; i < vertices.size(); i++) {
    heap.insert(Edge(i_src, i, distances[i], costs[i]));
  }
  while (!heap.isEmpty()) {
    // get the min edge
    Edge e = heap.delete_min();
    // shortest path reached: print data
    if (e.dest == i_dest) {
      if (e.distance == INT_MAX)
        return;
      std::cout << src.getData() << "->" << dst.getData() << ". The length is "
                << e.distance << ". The cost is " << e.cost << "." << std::endl;
    }
    if (e.distance == INT_MAX)
      continue;
    // update distances and costs
    for (int i = 0; i < edges[e.dest].size(); i++) {
      Edge edge = edges[e.dest][i];
      if (edge.distance + e.distance < distances[edge.dest]) {
        distances[edge.dest] = edge.distance + e.distance;
        costs[edge.dest] = edge.cost + e.cost;
        heap.decrease_key(
            edge.dest,
            Edge(edge.dest, edge.dest, distances[edge.dest], costs[edge.dest]));
      }
    }
  }
}

void task_2(Graph<std::string> airports, std::string origin,
            std::string destination) {
  Vertex<std::string> originVertex = airports.getVertex(origin);
  Vertex<std::string> destinationVertex = airports.getVertex(destination);
  // case for no path
  std::cout << "Shortest route from " << origin << " to " << destination
            << ": ";
  dijkstra(airports, originVertex, destinationVertex);
  if (origin == destination) {
    std::cout << "None" << std::endl;
  }
  // take origin vertex and destination vertex
  // dijkstra(airports, originVertex, destinationVertex);
}
#endif