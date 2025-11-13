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

  void display() {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        cout << setw(4) << data[i][j];
      }
      cout << endl;
    }
  }

  void setSize(int n) {
    size = n;
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

  Matrix operator+(Matrix const &other) {
    Matrix res;
    res.size = size;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        res.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return res;
  }

  Matrix operator*(Matrix const &other) {
    Matrix res;
    res.size = size;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        res.data[i][j] = 0;
        for (int k = 0; k < size; k++) {
          res.data[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }
    return res;
  }

  void diagonalSum() {
    int mainSum = 0;
    int secondSum = 0;
    for (int i = 0; i < size; i++) {
      mainSum += data[i][i];
      secondSum += data[i][size - i  - 1];
    }
    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Secondary diagonal sum: " << secondSum << endl;
  }
};
