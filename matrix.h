#include <iostream>
#include <fstream>
#include <iomanip>
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

  void display() {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        cout << setw(4) << data[i][j];
      }
      cout << endl;
    }
  }

  int getSize() {
    return size;
  }

  int getVal(int i, int j) {
    return data[i][j];
  }

  void setVal(int i, int j, int val) {
    data[i][j] = val;
  }
};
