#ifndef DARWIN_DEB_DEB_H
#define DARWIN_DEB_DEB_H

class NeuralNetwork;

class Deb {
 private:
  double x;
  double y;
  double velX;
  double velY;
  NeuralNetwork bra
 public:
  const static int inputCount = 4;
  Deb();
  Deb(double posX, double posY);
  void update();
};

#endif
