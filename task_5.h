#ifndef TASK_5_H
#define TASK_5_H

#include "Graph.h"
#include "Vertex.h"
#include "Queue.h"
#include "Queue.cpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/*
INT COUNT = 0
WE HAVE VECTOR VERTICES
GO THROUGH THE VERTICES VECTOR
  // getVertex()

INSIDE LOOP
RESET COUNT TO 0
WE HAVE VECTOR EDGES
GO THROUGH ALL THE EDGES
  // for(int i=0; i < getEdges().size(); i++)

INSIDE THAT LOOP
IF VERTEX = SRC OR DEST 
  // Yes, considering "both outbound and inbound flights"
INCREMENT COUNT BY 1

WHEN OUTSIDE EDGE LOOP
PRINT VERTEX 3 LETTER CODE, SOME SPACES, AND THEN THE COUNT NUMBER
THEN YOU GO TO THE NEXT VERTEX IN THE VECTOR

*/


template <typename T>
void task_5(Graph<T> g) {
  int count = 0;
  for(int i=0; i < g.getVertices().size(); i++) {
    T v = g.getVertices().at(i).getData();
    for(int j=0; j < g.getEdges().size(); j++) {
      for(int k=0; k < g.getEdges().at(j).size(); k++) {
        Edge e = g.getEdges().at(j).at(k);
        T e1 = g.getVertices().at(e.src).getData();
        T e2 = g.getVertices().at(e.dest).getData();
        if(v == e1 || v == e2) {
          count++;
        }
      }
    }
  }
}

#endif