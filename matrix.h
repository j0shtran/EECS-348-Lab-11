#include <iostream>
#include <fstream>
using namespace std;

class Matrix {
private:
  int size;
  int data[20][20];
public:
  Matrix() {
    size = 0;
  }

  void readFile(ifstream &file) {
    file >> size;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        file >> data[i][j];
      }
    }
  }
};
