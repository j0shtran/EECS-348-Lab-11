#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Matrix {
private:
  int size; //declares int variable size 
  int data[20][20]; //declares int variable data to store the values, max size of 20
public:
  Matrix() {
    size = 0; //uses the int variable size we declared earlier 
  }

  void display() { //prints the matrix in a nice format 
    for (int i = 0; i < size; i++) { //for each row 
      for (int j = 0; j < size; j++) { //for each column 
        cout << setw(4) << data[i][j]; //prints the value with width 4 apart 
      }
      cout << endl;
    }
  }

  void setSize(int n) { //sets the size of the matrix to given n 
    size = n;
  }
  int getSize() {
    return size; //returns the size of the matrix
  }

  int getVal(int i, int j) {
    return data[i][j]; //returns the value at a given index 
  }

  void setVal(int i, int j, int val) {
    data[i][j] = val; //sets the value at a given index 
  }

  Matrix operator+(Matrix const &other) { //overloaded addition operator 
    Matrix res; //calls a Matrix res
    res.size = size; //sets the size to the same size as original matrix 
    for (int i = 0; i < size; i++) { //for each row 
      for (int j = 0; j < size; j++) { //for each column 
        res.data[i][j] = data[i][j] + other.data[i][j]; //adds the original matrix and the other matrix 
      }
    }
    return res; //returns the matrix with the sum of both matrices 
  }

  Matrix operator*(Matrix const &other) { //overloaded multiplication operator 
    Matrix res; //calls a Matrix for the result 
    res.size = size; //sets the results size to the original matrix 
    for (int i = 0; i < size; i++) { //for each row 
      for (int j = 0; j < size; j++) { //for each column 
        res.data[i][j] = 0; //sets the value of the result matrix to zero 
        for (int k = 0; k < size; k++) { 
          res.data[i][j] += data[i][k] * other.data[k][j]; //multiplies the two matrices value by value 
        }
      }
    }
    return res; //returns result matrix 
  }

  void diagonalSum() { //sums the main and secondary diagonals of a matrix
    int mainSum = 0; // declares int variable mainSum 
    int secondSum = 0; //declares int variable secondSum 
    for (int i = 0; i < size; i++) { //for every column
      mainSum += data[i][i]; //sums up the main column 
      secondSum += data[i][size - i  - 1]; //sums up the secondary column
    }
    cout << "Main diagonal sum: " << mainSum << endl; //prints the main sum 
    cout << "Secondary diagonal sum: " << secondSum << endl; //prints the secondary sum
  }


  void swapRows(Matrix tmpMatrix, int r1 = 0, int r2 = 1) { //swaps two given rows 
    if (r1 < 0 || r1 >= tmpMatrix.size || r2 < 0 || r2 >= tmpMatrix.size) { //checks to make sure given rows are in the bounds 
      cout << "Invalid rows!" << endl; //if invalid, prints error message``
      return; //and ends the function
    }

    for (int j = 0; j < tmpMatrix.size; j++) { //for every value in the row 
      int temp = tmpMatrix.data[r1][j]; //declares a temp value int and sets it to the temp matrix 
      tmpMatrix.data[r1][j] = tmpMatrix.data[r2][j]; //sets the first row data to the corresponding second rows data 
      tmpMatrix.data[r2][j] = temp; //sets the second rows data
    }

    tmpMatrix.display(); //prints the final matrix
  }

  void swapCols(Matrix tmpMatrix, int c1 = 0, int c2 = 1) { //swaps two given columns 
    if (c1 < 0 || c1 >= tmpMatrix.size || c2 < 0 || c2 >= tmpMatrix.size) { //makes sure the given columns are within the bounds 
      cout << "Invalid columns!" << endl; //if not, prints error message
      return; //and ends the function 
    }

    for (int i = 0; i < tmpMatrix.size; i++) { //essentially the same process as swap rows. the only difference is it iterates through rows instead of columns
      int temp = tmpMatrix.data[i][c1];
      tmpMatrix.data[i][c1] = tmpMatrix.data[i][c2];
      tmpMatrix.data[i][c2] = temp;
    }
    
    tmpMatrix.display(); //prints the resulting matrix 
  }

  void update(int r, int c, int val) {
    if (r < 0 || r >= size || c < 0 || c >= size) { //checks to make sure given index is valid 
      cout << "Invalid input..." << endl;
      return;
    }

    data[r][c] = val; //sets the given index to the given value 
    display(); //prints the resulting matrix 
  }
};
