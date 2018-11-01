#include "matrix.h"
#include <iostream>
using namespace std;



Matrix Matrix::operator+ (Matrix mat)
{
    assert((this->rows = mat.rows) && (this->cols = mat.cols));
    Matrix res (mat.rows, mat.cols);
    for (int i=0; i<res.rows; i++)
        for (int j=0; j<res.cols; j++)
            res.data[i][j] = this->data[i][j] + mat.data[i][j];
    return res;
}


Matrix Matrix::operator- (Matrix mat)
{
    assert((this->rows = mat.rows) && (this->cols = mat.cols));
    Matrix res (mat.rows, mat.cols);
    for (int i=0; i<res.rows; i++)
        for (int j=0; j<res.cols; j++)
            res.data[i][j] = this->data[i][j] - mat.data[i][j];
    return res;
}


Matrix Matrix::operator*  (Matrix mat)
{
    assert(this->cols = mat.rows);
    Matrix res (this->rows, mat.cols);
    for (int i=0; i<res.rows; i++)
        for (int j=0; j<res.cols; j++)
        {
            int sum=0;
            for (int k=0; k<this->cols; k++)
                sum += this->data[i][k] * mat.data[k][j];
            res.data[i][j] = sum;
        }
    return res;
}


Matrix Matrix::operator+  (int scalar)
{
    Matrix res (this->rows, this->cols);
    for (int i=0; i<res.rows; i++)
        for (int j=0; j<res.cols; j++)
            res.data[i][j] = this->data[i][j] + scalar;
    return res;
}


Matrix Matrix::operator-  (int scalar)
{
    Matrix res (this->rows, this->cols);
    for (int i=0; i<res.rows; i++)
        for (int j=0; j<res.cols; j++)
            res.data[i][j] = this->data[i][j] - scalar;
    return res;
}


Matrix Matrix::operator*(int scalar)
{
    Matrix res (this->rows, this->cols);
    for (int i=0; i<res.rows; i++)
        for (int j=0; j<res.cols; j++)
            res.data[i][j] = this->data[i][j] * scalar;
    return res;
}


Matrix Matrix::operator= (Matrix mat)
{
    this->rows = mat.rows ;
    this ->cols = mat.cols;
    this->data = new int* [mat.rows];
    for (int i = 0 ; i < mat.rows ; i++)
        this->data[i] = new int [mat.cols];
    for (int i = 0 ; i<mat.rows ; i++)
    {
        for (int j = 0 ; j<mat.cols ; j++)
            this->data[i][j] = mat.data[i][j];
    }
}


istream& operator>> (istream& in,Matrix mat)
{
    for(int i=0; i<mat.rows; i++)
    {
        for(int j=0; j<mat.cols; j++)
        {
            cout<<"Enter the element of the row: "<<i+1<<" and column: "<<j+1<<": ";
            in>>mat.data[i][j];
        }
    }
}


ostream& operator<< (ostream& out,Matrix mat)
{
    for(int i=0; i<mat.rows; i++)
    {
        for(int j=0; j<mat.cols; j++)
        {
            out<<mat.data[i][j]<<" ";
        }

        cout<<endl;
    }
    cout<<endl;
}


Matrix::Matrix(int rows,int cols)
{
    this->rows=rows;
    this->cols=cols;
    data=new int *[rows];
    for(int i=0; i<rows; i++)
        data[i]=new int [cols];
}


Matrix &Matrix:: operator+=( Matrix &mat1)
{
    for (int i = 0 ;  i<mat1.rows; i++)
    {
        for (int j = 0 ; j<mat1.cols ; j++)
        {
            this->data[i][j]= this->data[i][j] + mat1.data[i][j];
        }
    }
    return *this;
}


Matrix &Matrix::operator-=(Matrix &mat1)
{
    for (int i = 0 ;  i<mat1.rows; i++)
    {
        for (int j = 0 ; j<mat1.cols ; j++)
        {
            this->data[i][j] -= mat1.data[i][j];
        }
    }
    return *this;

}



Matrix &Matrix::operator++()
{
    for (int i = 0 ;  i<this->rows; i++)
    {
        for (int j = 0 ; j<this->cols ; j++)
        {
            this->data[i][j]++;
        }
    }
    return *this;
}


Matrix &Matrix::operator--()
{
    for (int i = 0 ;  i<this->rows; i++)
    {
        for (int j = 0 ; j<this->cols ; j++)
        {
            this->data[i][j]--;
        }
    }
    return *this;
}


Matrix &Matrix::operator+=(int scalar)
{
    for (int i = 0 ;  i<this->rows; i++)
    {
        for (int j = 0 ; j<this->cols ; j++)
        {
            this->data[i][j] += scalar;
        }
    }
    return *this;
}


Matrix &Matrix::operator-=(int scalar)
{
    for (int i = 0 ;  i<this->rows; i++)
    {
        for (int j = 0 ; j<this->cols ; j++)
        {
            this->data[i][j] -= scalar;
        }
    }
    return *this;
}


bool Matrix::operator== (Matrix mat)
{
    if((this->rows==mat.rows)&&(this->cols==mat.cols))
    {
        for (int i = 0 ; i < mat.rows ; i++)
        {
            for (int j = 0 ; j < mat.cols ; j++)
            {
                if(this->data[i][j]!=mat.data[i][j])
                    return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}



bool Matrix::operator!= (Matrix mat)
{
    if((this->rows==mat.rows)&&(this->cols==mat.cols))
    {
        for (int i = 0 ; i < mat.rows ; i++)
        {
            for (int j = 0 ; j < mat.cols ; j++)
            {
                if(this->data[i][j]!=mat.data[i][j])
                    return true;
            }
        }
        return false;

    }
    else
    {
        return true;
    }
}


bool Matrix::isSquare()
{
    return this->rows==this->cols?true:false;
}


bool Matrix::isSymetric ()
{
    if(this->rows==this->cols)
    {
        for (int i = 0 ; i < this->rows ; i++)
        {
            for (int j = 0 ; j < this->cols ; j++)
            {
                if(this->data[j][i]!=this->data[i][j])
                    return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}


bool Matrix::isIdentity ()
{
    if(this->rows==this->cols)
    {
        for (int i = 0 ; i < this->rows ; i++)
        {
            for (int j = 0 ; j < this->cols ; j++)
            {
                if(i==j)
                {
                    if(this->data[i][j]!=1)
                        return false;
                }
                else
                {
                    if(this->data[i][j]!=0)
                        return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}


Matrix Matrix:: transpose()
{
    Matrix temp(this->cols,this->rows);
    for (int i = 0 ; i < temp.rows ; i++)
    {
        for (int j = 0 ; j < temp.cols ; j++)
        {
            temp.data[i][j]=this->data[j][i];
        }
    }
    return temp;
}
