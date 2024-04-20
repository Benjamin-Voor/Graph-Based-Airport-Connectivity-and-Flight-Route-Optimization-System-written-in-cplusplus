#ifndef TASK3_H
#define TASK3_H

#include "Graph.cpp"
#include "Graph.h"
#include "Vertex.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Task 3: Find all shortest paths between the given origin airport and all the airports in the destination state. The algorithm should output all the paths and their lengths. The algorithm should provide the appropriate message if no such paths exist. 

void task_3(Graph<std::string> &airports, std::string origin,  std::string destination, std::string state) {
  // case for no path existing
  if(origin == destination) {
    cout << "Path does not exist" << endl;
  }
  // find all the destination state airports and add them to an array

  
  std::string destination_state_airports[] = {};
  // Use a modified Dijkstra's algorithm that does not stop after finding the shortest path for each destination state airport
  for(std::string destination_state_airport : destination_state_airports) {
  airports.dijkstra_shortest_path(origin, destination);
  }
  // Instead, continue until all airports in the destination state have been reached or all possible paths have been exhausted
  
  // Store paths and their lengths in a map
  
  // Print the map
  
}

#endif