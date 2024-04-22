#ifndef TASK_5_H
#define TASK_5_H

#include "Graph.h"
#include "Queue.cpp"
#include "Queue.h"
#include "Vertex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/*
  Ben's PSEUDOCODE:
  START
  For all vertices
    get the three letter code = v
    for all vectors in "edges"
      for every Edge in the vector
        get the edge = e
        get the source of the Edge, as a three letter code = e1
        get the destination of the Edge, as a three letter code = e2
        if three letter code equals source or destination
          increment count
          cout \t count
        finally, cout everything else
    END
*/

template <typename T> void task_5(Graph<T> g) {
  int count = 0;
  std::cout << "Every paragraph is an edge" << std::endl << std::endl;
  for (int i = 0; i < g.getVertices().size(); i++) {
      // for all vertices
    
    T v = g.getVertices().at(i).getData();
    
    for (int j = 0; j < g.getEdges().size(); j++) {
      for (int k = 0; k < g.getEdges().at(j).size(); k++) {
        Edge e = g.getEdges().at(j).at(k);
        T e1 = g.getVertices().at(e.src).getData();
        T e2 = g.getVertices().at(e.dest).getData();
        if (v == e1 || v == e2) {
          count++;
        }
        std::cout << "Vertices[" << i << "] = " << v << std::endl << "edges[" << j << "][" << k << ']' << std::endl << "Origin_airport: " << e1 << ", Destination_airport: " << e2 << std::endl << "count: " << count << std::endl << std::endl;
      }
    }
  }
}

#endif