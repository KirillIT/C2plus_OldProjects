#include <iostream>

using namespace std;

bool findOut(int** arr, int row, int col, int startX, int startY, int finalX, int finalY) {
    cout << "Вызвалась функция" << endl;
    arr[startX][startY] = 2;
    if (startX == finalX && startY == finalY) {
        cout << "Выход нашёлся!!!" << endl;
       
        return true;
    }

    if (startX - 1 >= 0) {
        if (arr[startX - 1][startY] != 2 && arr[startX - 1][startY] != 1) {
            if (findOut(arr, row, col, startX - 1, startY, finalX, finalY)) {
            
                return true;
            }
        }
    }

    if (startX + 1 < row) {
        if (arr[startX + 1][startY] != 2 && arr[startX + 1][startY] != 1) {
            if (findOut(arr, row, col, startX + 1, startY, finalX, finalY)) {

                return true;

            }
        }
    }

    if (startY - 1 >= 0) {
        if (arr[startX][startY - 1] != 2 && arr[startX][startY - 1] != 1) {
            if (findOut(arr, row, col, startX, startY - 1, finalX, finalY)) {

                return true;

            }
       
      }
    }

    if (startY + 1 < col) {
        if (arr[startX][startY + 1] != 2 && arr[startX][startY + 1] != 1) {
            if (findOut(arr, row, col, startX, startY + 1, finalX, finalY)) {
                return true;

            }
        }
    }
    return false;

}

int main(){
    
    const int row = 5;

    const int col = 5;

    int** arr = new int* [row];

    for (int i = 0; i < row; i++) {
    
        arr[i] = new int[col];

    }

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            cin >> arr[i][j];
        }
    }

    /*
    
    0 0 0 0 0
    0 0 0 0 1    
    0 0 1 1 0
    0 0 0 1 1
    0 0 0 0 0

    */
    
  
    cout << findOut(arr, row, col, 0, 0, row - 1, col - 1) << endl;

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++) {

        delete[] arr[i];

    }

    delete[] arr;

}