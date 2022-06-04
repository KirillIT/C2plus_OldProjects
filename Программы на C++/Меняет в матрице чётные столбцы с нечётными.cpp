#include <iostream>

using namespace std;

int main() {

    int N, M;

    cout << "Enter the number of rows in the matrix: ";

    cin >> N;

    cout << endl;

    cout << "Enter the number of columns in the matrix: ";
    
    cin >> M;

    cout << endl;

    int** arr = new int* [N];

    for (int i = 0; i < N; i++) {

        arr[i] = new int[M];
    
    }

    cout << "Source array:" << endl;

    for (int i = 0; i < N; i++) {
    
        for (int j = 0; j < M; j++) {
        
            arr[i][j] = rand() % 9 + 1;
        
            cout << arr[i][j] << " ";

        }
        
        cout << endl;

    }

    cout << endl;

    int finalIndex;

    if (M % 2 == 0) {
    
        finalIndex = M - 1;

    }

    else {

        finalIndex = M - 2;
    
    }

    int firstAuxiliaryIndex = 0;

    int secondAuxiliaryIndex = 1;

    int** finalArr = new int* [N];

    for (int i = 0; i < N; i++) {

        finalArr[i] = new int[M];

    }

    int index;

    int startingValue = 0;

    while (secondAuxiliaryIndex != finalIndex + 2) {

        for (int i = 0; i < N; i++) {

            index = startingValue;

            for (int j = secondAuxiliaryIndex; j >= firstAuxiliaryIndex; j--) {

                finalArr[i][index++] = arr[i][j];

            }
        }

        firstAuxiliaryIndex += 2;

        secondAuxiliaryIndex += 2;

        startingValue += 2;

    }

    if (M % 2 == 1) {
    
        for (int i = 0; i < N; i++) {

            finalArr[i][M - 1] = arr[i][M - 1];

        }
    }

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < M; j++) {

            cout << finalArr[i][j] << " ";

        }

        cout << endl;

    }

    for (int i = 0; i < N; i++) {

        delete[] finalArr[i];

    }

    for (int i = 0; i < N; i++) {
    
        delete[] arr[i];

    }

    delete[] finalArr;

    delete[] arr;

    system("pause");

}