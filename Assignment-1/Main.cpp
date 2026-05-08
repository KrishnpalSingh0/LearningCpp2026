#include<iostream>
#include "MatrixOperations.h"
using namespace std;
void addition(){
     int row1, col1, row2, col2;
                cout<<"Enter rows of First Matrix: ";
                cin>>row1;
                cout<<"Enter columns of First Matrix: ";
                cin>>col1;
                cout<<"Enter rows of Second Matrix: ";
                cin>>row2;
                cout<<"Enter columns of Second Matrix: ";
                cin>>col2;
                if(!isValidSize(row1, col1) || !isValidSize(row2, col2)){
                  return;
                }
                if (row1 == row2 && col1 == col2){
                int** aMatrix = createMatrix(row1, col1);
                int** bMatrix = createMatrix(row2, col2);
                cout<<"Enter First Matrix:"<<endl;
                inputMatrix(aMatrix, row1, col1);
                cout<<"Enter Second Matrix:"<<endl;
                inputMatrix(bMatrix, row2, col2);
                addMatrix(aMatrix, bMatrix, row1, col1, row2, col2);
                deleteMatrix(aMatrix, row1);
                deleteMatrix(bMatrix, row2);
                }
                else{
                     cout<< "Addition not possible both matrix must have same size"<<endl;
                }
}

void multiplication(){
      int row1, col1, row2, col2;
                cout<<"Enter rows of First Matrix: ";
                cin>>row1;
                cout<<"Enter columns of First Matrix: ";
                cin>>col1;
                cout<<"Enter rows of Second Matrix: ";
                cin>>row2;
                cout<<"Enter columns of Second Matrix: ";
                cin>>col2;
                if(!isValidSize(row1,col1) || !isValidSize(row2,col2)) {
                   return;
                }
                if(col1 == row2){
                int** aMatrix = createMatrix(row1, col1);
                int** bMatrix = createMatrix(row2, col2);
                cout<<"Enter First Matrix:"<<endl;
                inputMatrix(aMatrix, row1, col1);
                cout<<"Enter Second Matrix:"<<endl;
                inputMatrix(bMatrix, row2, col2);
                multiplyMatrix(aMatrix, bMatrix, row1, col1, row2, col2);
                deleteMatrix(aMatrix, row1);
                deleteMatrix(bMatrix, row2);}
                else{
                    cout<<"Columns of Matrix 1 must equal Rows of Matrix 2"<<endl;
                }
}
int main() {
    int choice;
    int choiceCounter =0;
       while (choiceCounter <10){
        cout<< "Enter 1 for Addition,\nEnter 2 for Multiplication,\nEnter 0 for Exit"<<endl;
        cin >> choice;
            switch (choice) {
            case 1: {
                addition();
                break;
            }
            case 2: {
                multiplication();
                break;
            }
            case 0: {
                cout << "Program end"<<endl;
                return 0;
            }
            default: {
                cout << "Invalid Choice'\n"<<endl;
            }
        }
        choiceCounter ++;     
    }  
    return 0;
}