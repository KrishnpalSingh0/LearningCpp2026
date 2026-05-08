#include <iostream>
using namespace std;
#include "MatrixOperations.h"

bool isValidSize(int row, int col){
    if (row <= 0 || col <= 0){
        cout<<"Invalid size"<<endl;
        return false;
    }
    return true;
}
int** createMatrix(int row, int col){
    int** matrix = new int*[row];
    for (int i=0; i<row; i++){
        matrix[i] = new int[col]();
    }
    return matrix;
}
void inputMatrix(int** matrix, int row, int col){  
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            int cnt=0;
            while (cnt<10)
            {
              cout << "Enter element at ["<<i<<"]["<<j<<"] : ";
              cin >> matrix[i][j];
              if(cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<"Invalid input enter integer only"<<endl;
              }
              else{
                break;
              }
              cnt ++;
            }                     
        }
    }
}
void displayMatrix(int** matrix, int row, int col){
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void addMatrix(int** a, int** b, int row1, int col1, int row2, int col2){
    int** result = createMatrix(row1, col1);
    for (int i=0; i<row1; i++){
        for (int j=0; j<col1; j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    cout<<"Addition Result:"<<endl;
    displayMatrix(result, row1, col1);
    deleteMatrix(result, row1);
}
void multiplyMatrix(int** a, int** b, int row1, int col1, int row2, int col2){
    int** result = createMatrix(row1,col2);
    for (int i=0; i <row1; i++){
        for (int j=0; j<col2; j++){
            result[i][j] = 0;
            for (int k=0; k<col1; k++){
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "Multiplication Result:"<<endl;
    displayMatrix(result, row1, col2);
    deleteMatrix(result, row1);
}
void deleteMatrix(int** matrix, int row){
    if(matrix == NULL){
        return;
    }
    for (int i = 0; i < row; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}