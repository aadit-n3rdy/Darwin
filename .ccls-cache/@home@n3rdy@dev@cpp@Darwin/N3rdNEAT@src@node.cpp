#include "node.h"
#include <list>
#include <vector>
#include <iostream>
#include "connector.h"
#include <cmath>

double Node::sigmoid(double input) {
  return input/(std::abs(input)+(double)1);
}


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
    std::cout << "ERROR: Attempted remove of disconnected from connector\n";
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
    std::cout << "ERROR: Attempted remove of disconnected to connector";
  }
  else {
    to.erase(to.begin() + index);
  }
}
void Node::calc() {
  if(!updated) {
    int fromLen = from.size();
    double* fromResults = (double*)std::calloc(fromLen, sizeof(double));
    if(fromResults == nullptr) {
      std::cerr << "calloc failed in Node::calc()";
      std::__throw_bad_alloc();
    }
    Node* temp = nullptr;
    for(int i = 0; i < fromLen; i++) {
      temp = from[i]->getFrom();
      temp->calc();
      double tempResult = temp->getVal()*from[i]->getConnectionWeight();
      fromResults[i] = temp->getVal()*from[i]->getConnectionWeight();
    }
    //TODO: Code to calculate actual value if using multiple node types
    
  }
}
void Node::prepareSelfDestroy() {
  int fromLen = from.size();
  int toLen = to.size();
  for(int i = 0; i < fromLen; i++) {
    from[i]->getFrom()->removeToConnector(from[i]);
    std::free(from[i]);
  }
  for(int i = 0; i < toLen; i++) {
    to[i]->getTo()->removeFromConnector(to[i]);
    std::free(to[i]);
  }
}
