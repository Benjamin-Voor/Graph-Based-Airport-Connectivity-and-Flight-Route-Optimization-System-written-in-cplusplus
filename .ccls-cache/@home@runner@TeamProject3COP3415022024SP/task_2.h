#ifndef TASK_2_H
#define TASK_2_H
#include "Graph.h"
#include "Vertex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
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

void dijkstra(Graph<std::string> airports, Vertex<std::string> origin,
              Vertex<std::string> destination) {
  int i_src = airports.get_vertex_index(origin);
  int i_dest = airports.get_vertex_index(destination);

  if (i_src == -1 || i_dest == -1) {
    throw std::string("Shortest path: incorrect vertices");
  }
  std::vector<Vertex<std::string>> vertices = airports.getVertices();
  std::vector<std::vector<Edge>> edges = airports.getEdges();

  airports.clean_visited();
  std::vector<int> distances(vertices.size()); // represents the distances from
                                               // source to all other vertices
  // set initial distances
  for (int i = 0; i < distances.size(); i++) {
    distances[i] =
        (i == i_src) ? 0 : INT_MAX; // 0 if source, infinite otherwise
  }
}

void task_2(Graph<std::string> airports, std::string origin,
            std::string destination) {
  Vertex<std::string> originVertex = airports.getVertex(origin);
  Vertex<std::string> destinationVertex = airports.getVertex(destination);
  // case for no path
  if (origin == destination) {
    std::cout << "Shortest route from " << origin << " to " << destination << ": None" << std::endl;
  }
  // take origin vertex and destination vertex
  //dijkstra(airports, originVertex, destinationVertex);
}
#endif