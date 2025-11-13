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
  int r1; //calls int variable r1
  int r2; //calls int variable r2
  cout << "Enter a row: "; //prompts user for row 1
  cin >> r1;
  cout << "Enter a row to swap with: "; //prompts user for row 2
  cin >> r2;
  A.swapRows(A, r1, r2); //uses the swapRows function to swap the two rows and print the resulting matrix

  return 0;
}
