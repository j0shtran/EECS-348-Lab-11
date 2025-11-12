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

  Matrix A, B;
  A.readFile(file);
  B.readFile(file);

  cout << "Matrix A: \n";
  A.display();

  cout << "Matrix B: \n";
  B.display();

  return 0;
}
