#ifndef MATRIXCALCULATOR_H_INCLUDED
#define MATRIXCALCULATOR_H_INCLUDED
#include"Matrix.h"
class MatrixCalculator{
public:
    template<class T>
    void Menu();
};
template<class T>
void MatrixCalculator::Menu() {
    cout << "Welcome to (Dina) Matrix Calculator '-'\n"
            "-------------------------------------------------------" << endl;
    while (true) {
        cout << "1- Perform Matrix Addition\n"
                "2- Perform Matrix Subtraction\n"
                "3- Perform Matrix Multiplication\n"
                "4- Matrix Transpose\n";
        cout<<"Please enter Number of the operation you want or 0 to Exit \n";
        char ch ;
        cin >> ch;
        if(ch == '0'){
            cout <<"Quitting Matrix Calculator...." << endl ;
            break ;
        }
        cout << "Enter the dimensions (rows & cols) of your 1st Matrix" << endl;
        int r1, c1;
        cin >> r1 >> c1;
        Matrix<T> mat_1(r1, c1);
        cout << "Now Enter your Matrix" << endl;
        cin >> mat_1;
        if (ch == '1') {
            cout << "Enter the dimensions (rows & cols) of your 2nd Matrix" << endl;
            int r2, c2;
            cin >> r2 >> c2;
            Matrix<T> mat_2(r2, c2);
            cout << "Now Enter your Matrix" << endl;
            cin >> mat_2;
            if (r1 != r2 || c1 != c2)
                cout<< "The operation couldn't be completed , rows & columns of the two matrices must be consistent \n";
            else {
                Matrix<T> res = mat_1 + mat_2;
                cout <<"The Summation of two matrices is \n";
                cout << res << endl;
            }
        }
        else if (ch == '2') {
            cout << "Enter the dimensions (rows & cols) of your 2nd Matrix" << endl;
            int r2, c2;
            cin >> r2 >> c2;
            Matrix<T> mat_2(r2, c2);
            cout << "Now Enter your Matrix" << endl;
            cin >> mat_2;
            if (r1 != r2 || c1 != c2)
                cout<< "The operation couldn't be completed , rows & columns of the two matrices must be consistent \n";
            else {
                Matrix<T> res = mat_1 - mat_2;
                cout <<"The Subtraction of two matrices  is \n";
                cout << res << endl ;
            }
        }
        else if (ch == '3'){
            cout << "Enter the dimensions (rows & cols) of your 2nd Matrix" << endl;
            int r2, c2;
            cin >> r2 >> c2;
            Matrix<T> mat_2(r2, c2);
            cout << "Now Enter your Matrix" << endl;
            cin >> mat_2;
            if(c1 != r2)
                cout<<"The condition of multiplication is not satisfied so operation could not be completed"<<endl;
            else{
                Matrix<T> res = (mat_1 * mat_2);
                cout <<"The Multiplication of two matrices is \n";
                cout << res << endl ;
            }
        }
        else if (ch == '4') {
            cout << "The Transpose of the matrix is \n";
            cout << mat_1.getTranspose()<< endl;
        }
        else
            cout <<"Undefined Operation was entered"<< endl ;
        }

}



#endif // MATRIXCALCULATOR_H_INCLUDED
