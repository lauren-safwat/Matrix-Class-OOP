#include "matrix.h"
#include <iostream>

using namespace std;

int main()
{
    Matrix mat1(3,3);
    cin >> mat1;
    cout << "Matrix A = " << endl;
    cout << mat1;
    Matrix mat2(3,3);
    cin >> mat2;
    cout << "Matrix B = " << endl;
    cout << mat2;
    cout << endl;
    cout << "A + B = " << endl;
    cout << (mat1+mat2);
    cout << endl << endl;
    cout << "A - B = " << endl;
    cout << (mat1 - mat2);
    cout << endl << endl;
    cout << "A * B = " << endl;
    cout << (mat1 * mat2);
    cout << endl << endl;
    cout << "A + 3 = " << endl;
    cout << (mat1 + 3);
    cout << endl << endl;
    cout << "B - 1 = " << endl;
    cout << (mat2 - 1);
    cout << endl << endl;
    cout << "A * 2 = " << endl;
    cout << (mat1 * 2);
    cout << endl << endl;
    cout << "A += B"<<endl;
    cout << "Now A = " << endl;
    cout << (mat1 += mat2);
    cout << endl << endl;
    cout << "A -= B"<<endl;
    cout << "Now A = " << endl;
    cout << (mat1 -= mat2);
    cout << endl << endl;
    cout << "A += 5"<<endl;
    cout << "Now A = " << endl;
    cout << (mat1 += 5);
    cout << endl << endl;
    cout << "A -= 4"<<endl;
    cout << "Now A = " << endl;
    cout << (mat1 -= 4);
    cout << endl << endl;
    ++mat1;
    cout << "A++" << endl << "Now A = " << endl;
    cout << mat1;
    cout << endl << endl;
    --mat1;
    cout << "A--" << endl << "Now A = " << endl;
    cout << mat1;
    cout << endl << endl;
    cout << "Is matrix A = matrix B ?" << endl;
    cout << (mat1 == mat2);
    cout << endl << endl;
    cout << "Is matrix A != matrix B ?" << endl;
    cout << (mat1 != mat2);
    cout << endl << endl;
    cout << "Is matrix A square ?" << endl;
    cout << mat1.isSquare();
    cout << endl << endl;
    cout << "Is matrix A symmetric ?" << endl;
    cout << mat1.isSymetric();
    cout << endl << endl;
    cout << "Is matrix A identity?" << endl;
    cout << mat1.isIdentity();
    cout << endl << endl;
    cout << "The transpose of matrix A =" << endl;
    cout << mat1.transpose();
    cout << endl << endl;

}


