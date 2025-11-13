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

  Matrix A;
  A.setSize(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int val; 
      file >> val;
      A.setVal(i, j, val);
    }
  }
  int c1;
  int c2;
  cout << "Enter a column: ";
  cin >> c1;
  cout << "Enter a column to swap with: ";
  cin >> c2;
  A.swapCols(A, c1, c2); //exact same process as swapRows, just uses swapCols function instead.

  return 0;
}
