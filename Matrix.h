#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include<iostream>
using namespace std ;
template<class T>
class Matrix{
private:
    int row ;
    int col ;
    T **matt ;
public:

    Matrix(int r , int c );
    Matrix(const Matrix &obj);
    Matrix operator + (const Matrix &) ;
    Matrix operator - (const Matrix &) ;
    Matrix operator * (const Matrix &) ;
    Matrix getTranspose() const ;
    int getRow();
    int getCol();

    template<class T2>
    friend istream& operator>>(istream& is  ,Matrix<T2>& m);

    template<class T2>
    friend ostream& operator<<(ostream& os  ,const Matrix<T2>& m);
    ~Matrix();

};

template<class T>
int Matrix<T>::getRow() {
    return row;
}
template<class T>
int Matrix<T>::getCol() {
    return col;
}
//parameterized constructor to set values for rows and columns
template<class T>
Matrix<T>::Matrix(int r , int c) {
    row = r;
    col = c;
    matt = new T*[row] ;
    for(int i=0 ; i<row ; i++)
        matt[i]= new T[col] ;
}

//Copy Constructor
template<class T>
Matrix<T>::Matrix(const Matrix<T> &obj) {
    row = obj.row;
    col = obj.col;
    matt = new T*[row];
    for(int i=0 ; i<row ; i++)
        matt[i]= new T[col] ;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++)
            matt[i][j]=obj.matt[i][j];
    }
}


//Operator(+) to find summation of two matrices
template <class T>
Matrix<T> Matrix<T>::operator +(const Matrix & add){
    Matrix<T> temp(row , col);
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col; j++){
            temp.matt[i][j]=(matt[i][j] + add.matt[i][j]);
        }
    }
    return temp ;
}

//Operator(-) to find subtraction of two matrices
template <class T>
Matrix<T> Matrix<T>::operator -(const Matrix & sub){
    Matrix<T> temp(row , col);
    for(int i=0 ; i<row; i++){
        for(int j=0 ; j<col ; j++){
            temp.matt[i][j]=(matt[i][j] - sub.matt[i][j]);
        }
    }
    return temp ;
}
//Operator(*) to find multiplication of two matrices
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &multi) {
    Matrix<T> temp(row ,multi.col);

    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<multi.col ; j++){
            temp.matt[i][j]=0 ;
        }
    }
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<multi.col ; j++){
            for(int k=0 ; k<col ; k++){
                temp.matt[i][j]+=(matt[i][k]* multi.matt[k][j]);
            }
        }
    }
    return temp ;

}
//Function to get Transpose of the Matrix
template <class T>
Matrix<T> Matrix<T>::getTranspose() const {
    Matrix<T> trans (col , row);
    for(int i=0 ; i<col; i++){
        for(int j=0 ; j<row; j++){
            trans.matt[i][j] = matt[j][i] ;
        }
    }
    return trans;
}
//Overloading for the extraction operator >> to input elements of the Matrix.
template<class T2>
istream& operator>>(istream &is  ,Matrix<T2> &m){

    for(int i=0 ; i< m.getRow(); i++){
        for(int j=0 ; j<m.getCol(); j++){
            is>>m.matt[i][j];
        }
    }
    return is ;
}

//Overloading for the insertion operator << to output the Matrix.
template<class T2>
ostream &operator<<(ostream &os, const Matrix<T2> &m) {

    for(int i=0 ; i<m.row ; i++){
        for(int j=0 ; j<m.col; j++){
            os << m.matt[i][j] <<" ";
        }
        os << endl ;

    }
    return os ;
}

//Destructor to free Memory
template <class T>
Matrix<T>::~Matrix(){
    for(int i=0 ; i<row ; i++)
        delete matt [i] ;
    delete [] matt ;
}


#endif // MATRIX_H_INCLUDED
