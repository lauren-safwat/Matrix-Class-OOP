#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **data;
public:
    /** Default constructor **/
    Matrix();

    /** Parameter constructor **/
    Matrix(int rows,int cols);

    /** Assignment Operator **/
    Matrix operator= (Matrix mat);

    /** Output the matrix **/
    friend ostream& operator<< (ostream& out,Matrix mat);

    /** Input the elements of a matrix **/
    friend istream& operator>> (istream& in,Matrix mat);




    /** The function takes 2 matrices & returns a new matrix with their sum if the 2 matrices have the same dimensions **/
    Matrix operator+ (Matrix mat);

    /** The function takes 2 matrices & returns a new matrix with their difference if the 2 matrices have the same dimensions **/
    Matrix operator-  (Matrix mat);

    /** The function takes 2 matrices & returns a new matrix with their product if col1 = row2 **/
    Matrix operator*  (Matrix mat);

    /** Adding a scalar to a matrix and displaying the result in a new matrix **/
    Matrix operator+  (int scalar);

    /** Subtracting a scalar from a matrix and displaying the result in a new matrix **/
    Matrix operator-  (int scalar);

    /** Multiplying a matrix by a scalar and displaying the result in a new matrix **/
    Matrix operator*  (int scalar);




    /** The function takes 2 matrices & returns the first matrix with the sum **/
    Matrix &operator += ( Matrix &mat1);

    /** The function takes 2 matrices & returns the first matrix with the difference **/
    Matrix &operator -= ( Matrix &mat1);

    /** The function takes 1 matrix and return it with each of its values incremented **/
    Matrix &operator ++ ();

    /** The function takes 1 matrix and return it with each of its values decremented **/
    Matrix &operator -- ();

    /** The function takes a matrix and returns it after adding a value to its elements **/
    Matrix &operator += (int scalar);

    /** The function takes a matrix and returns it after subtracting a value from its elements **/
    Matrix &operator -= (int scalar);




    /** The function checks if 2 matrices are equal and returns a boolean value with the result **/
    bool   operator== (Matrix mat);

    /** The function checks if 2 matrices aren't equal and returns a boolean value with the result **/
    bool   operator!= (Matrix mat);

    /** The function checks if a matrix is square and returns a boolean value with the result **/
    bool   isSquare();

    /** The function checks if a matrix is symmetric and returns a boolean value with the result **/
    bool   isSymetric();

    /** The function checks if a matrix is identity and returns a boolean value with the result **/
    bool   isIdentity();

    /** The function takes a matrix and returns its transpose **/
    Matrix transpose();
};


#endif // MATRIX_H
