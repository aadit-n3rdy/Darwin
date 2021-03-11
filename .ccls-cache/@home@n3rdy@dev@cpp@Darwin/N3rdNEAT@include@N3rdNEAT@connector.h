#ifndef N3RD_NEAT_CONNECTOR_H
#define N3RD_NEAT_CONNECTOR_H

class Node;

class Connector {
 private:
  Node *from, *to;
  double weight;
 public:
  Connector();
  Connector(Node* fromNode, Node* toNode, double connectionWeight);
  inline Node* getFrom() { return from; }
  inline Node* getTo() { return to;}
  inline void setFrom(Node* fromNode) { from = fromNode; }
  inline void setTo(Node* toNode) { to = toNode; }
  inline double getConnectionWeight() { return weight; }
  inline void setConnectionWeight(double connectionWeight) { weight = connectionWeight; }
};

#endif


