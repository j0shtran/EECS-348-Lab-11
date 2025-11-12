#include <iostream>
#include "matrix.h"

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

  cout << "A + B = \n";
  Matrix C = A + B;
  C.display();

  return 0;
}
