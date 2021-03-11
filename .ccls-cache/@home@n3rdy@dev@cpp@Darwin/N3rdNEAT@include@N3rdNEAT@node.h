#ifndef N3RD_NEAT_NODE_H
#define N3RD_NEAT_NODE_H

#include <vector>

class Connector;
class NeuralNetwork;

enum NODE_TYPE {
  SIGMOID,
  SQUARE_ADD
};


class Node {
 private:
  std::vector<Connector*> from;
  std::vector<Connector*> to;
  double val;
  bool updated;
  NODE_TYPE type;
  static double sigmoid(double input);
 public:
  Node();
  inline void resetUpdated() { updated=false; }
  inline bool isUpdate() { return updated; }
  void calc();
  inline double getVal() { return val; }
  inline void addFromConnector(Connector* connector) {from.push_back(connector);}
  inline void addToConnector(Connector* connector) {to.push_back(connector);}
  void removeFromConnector(Connector* connector);
  void removeToConnector(Connector* connector);
  inline bool isObsolete() {return (from.size()==0) || (to.size()==0);}
  inline void updateType(NODE_TYPE newType) {
    updated = false;
    type = newType;
  }
  void prepareSelfDestroy();
  friend NeuralNetwork;
};

#endif
