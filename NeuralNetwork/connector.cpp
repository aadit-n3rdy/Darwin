#include "connector.h"
#include "node.h"

Connector::Connector() {
  from = nullptr;
  to = nullptr;
  weight = 1;
}

Connector::Connector(Node* fromNode, Node* toNode, double connectionWeight) {
  from = fromNode;
  to = toNode;
  weight = connectionWeight;
}
