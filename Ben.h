#ifndef BEN_H
#define BEN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

std::string readRow(std::fstream fin) {
  std::string line, word;

    // read an entire row and 
    // store it in a string variable 'line' 
    std::getline(fin, line);

    // Used for breaking words
    std::stringstream s(line);

    std::getline(s,word,',');
    return word; 
  }
  std::cout << "Error: readWord" << std::endl;
  return "";
}

#endif