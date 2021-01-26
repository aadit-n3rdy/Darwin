#include "node.h"
#include <vector>
#include <iostream>

class Connector;

Node::Node() {
  val = 0;
  from = std::vector<Connector *>();
  to = std::vector<Connector *>();
}

void Node::removeFromConnector(Connector* connector) {
  int len = from.size();
  int index = 0;
  bool end = false;
  for(int i = 0; (i < len) && !end; i++) {
    if(from[i] == connector) {
      index = i;
      end = true;
    }
  }
  if(!end) {
    std::cout << "ERROR: Attempted remove disconnected from connector\n";
  }
  else {
    from.erase(from.begin() + index);
  }
}

void Node::removeToConnector(Connector* connector) {
  int len = to.size();
  int index = 0;
  bool end = false;
  for(int i = 0; (i < len) && !end; i++) {
    if(to[i] == connector) {
      index = i;
      end = true;
    }
  }
  if(!end) {
    std::cout << "ERROR: Attempted remove disconnected to connector\n";
  }
  else {
    to.erase(to.begin() + index);
  }
}
