#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
  string filename;
  cout << "Enter filename: ";
  cin >> filename;
  ifstream file(filename);
  if (!file) {
    cout << "Invalid name";
    return 1;
  }
  int n;
  file >> n;

  Matrix A, B;
  A.setSize(n);
  B.setSize(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int val; 
      file >> val;
      A.setVal(i, j, val);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int val;
      file >> val;
      B.setVal(i, j, val);
    }
  }

  cout << "Matrix A: \n";
  A.diagonalSum(); //uses the diagonalSum function to print the diagonal sums for matrix a 
  cout << "Matrix B: \n";
  B.diagonalSum(); //same process, but for matrix B

  return 0;
}
