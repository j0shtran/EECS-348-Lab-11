#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
  string filename; //calls string variable filename
  cout << "Enter filename: "; //prompts user for filename
  cin >> filename; 
  ifstream file(filename); //attempts to open file using given name 
  if (!file) { //if file doesn't exist 
    cout << "Invalid name"; //prints error message
    return 1; //and ends with error 
  }
  int n; //calls int variable n 
  file >> n; //takes the first value from the file which is the size of the matrix and sets it to n 

  Matrix A, B; //calls two Matrices A and B using the Matrix class 
  A.setSize(n); //sets the size of A to n 
  B.setSize(n); //sets the size of B to n

  for (int i = 0; i < n; i++) { //for every row in size 
    for (int j = 0; j < n; j++) { //for every col in size 
      int val; //calls int variable val 
      file >> val; //takes the next values in the file which are the values of the matrices 
      A.setVal(i, j, val); //and sets those values to the matrix class
    }
  }

  for (int i = 0; i < n; i++) { //same process with matrix B 
    for (int j = 0; j < n; j++) {
      int val;
      file >> val;
      B.setVal(i, j, val);
    }
  }

  cout << "Matrix A: \n"; //prints the matrices 
  A.display();

  cout << "Matrix B: \n";
  B.display();

  return 0; //ends the function
}
