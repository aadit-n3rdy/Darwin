#ifndef DARWIN_NEURAL_NETWORK_NODE_H
#define DARWIN_NEURAL_NETWORK_NODE_H

#include <vector>

class Connector;

class Node {
 private:
  std::vector<Connector*> from;
  std::vector<Connector*> to;
  double val;
 public:
  Node();
  virtual void calc();
  inline double getVal() { return val; }
  inline void addFromConnector(Connector* connector) {from.push_back(connector);}
  inline void addToConnector(Connector* connector) {to.push_back(connector);}
  void removeFromConnector(Connector* connector);
  void removeToConnector(Connector* connector);
  inline bool isObsolete() {return (from.size()==0) || (to.size()==0);}
};

#endif
